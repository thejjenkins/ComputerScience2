#include "patrons.h"
#include "patron.h"
using namespace std;

void patrons::AddPatron(){
    string name;
    int id;
    float finebalance;
    int numbooksout;
    patron* newpatron;
    
    cout << "Enter name: "; getline(cin, name); 
    do{
        cout << "Enter ID: "; cin >> id; cin.ignore();
        if(this->SearchPatron(id)){
            cout << "ID already in use." << endl;
        }
    }while(this->SearchPatron(id));
    cout << "Enter the number of books in possession: "; cin >> numbooksout; cin.ignore();
    cout << "Enter the fines due in the form X.XX: "; cin >> finebalance; cin.ignore();
    newpatron = new patron(name, id, finebalance, numbooksout);
    patronlist.push_back(newpatron);
    cout << endl;
}
void patrons::EditPatron(){
    int id;
    cout << endl << "Enter ID: "; cin >> id; cin.ignore(); cout << endl;
    int index = this->FindPatron(id);
    if(index != -1){
        cout << "Edit name = 1\nEdit ID = 2\nEdit the number of books in possession = 3\nQuit = 0\n";
        int choice, newid, newbooksout;
        string newname;
        cout << "Choice: "; cin >> choice; cin.ignore(); cout << endl;
        switch(choice){
            case 1:
                cout << "Enter new name: "; getline(cin, newname);
                patronlist.at(index)->SetName(newname);
                cout << endl;
                break;
            case 2:
                do{
                    cout << "Enter ID: "; cin >> id; cin.ignore();
                    if(this->SearchPatron(id)){
                    cout << "ID already in use." << endl;
                    }
                }while(this->SearchPatron(id));
                patronlist.at(index)->SetID(id);
                cout << endl;
                break;
            case 3:
                cout << "Enter new number of books: "; cin >> newbooksout;
                patronlist.at(index)->SetNumBooksOut(newbooksout);
                cout << endl;
                break;
        }
    }
}
bool patrons::SearchPatron(int id){
    for(int i = 0; i < patronlist.size(); ++i){
        if((patronlist.at(i))->GetID() == id){
            return true;
        }
    }
    return false;
 }
int patrons::FindPatron(int id){
    for(int i = 0; i < patronlist.size(); ++i){
        if((patronlist.at(i))->GetID() == id){
            return i;
        }
    }
    cout << "Patron not found." << endl;
    return -1;
}
void patrons::DeletePatron(){
    // vector<patron*>::iterator it = patronlist.begin();
    // patron *currentpatron;
    // for(it; it != patronlist.end(); ++it){
    //     if((*it)->GetID() == id){
    //         patronlist.erase(it);
    //     }
    // }
    int id;
    cout << "Enter ID: "; cin >> id; cin.ignore();
    int index = this->FindPatron(id);
    if(index != -1){
        patronlist.erase(patronlist.begin()+index);
    }
    cout << "Deleted." << endl;
}
void patrons::PayFines(){
    int id;
    float newbalance;
    cout << "Enter ID: "; cin >> id; cin.ignore(); cout << endl;
    int index = this->FindPatron(id);
    if(index != -1){
        cout << "Enter new fine balance: "; cin >> newbalance;
        patronlist.at(index)->SetFineBalance(newbalance);
    }
    cout << endl;
}
void patrons::PrintAllPatrons(){
    vector<patron*>::iterator it = patronlist.begin();
    patron *currentpatron;
    cout << endl;
    for (it; it != patronlist.end(); ++it){
        currentpatron = *it;
        cout << "Name: " << currentpatron->GetName() << ". ID: " << currentpatron->GetID() << ". Has " << currentpatron->GetNumBooksOut() << " books. Owes $" << currentpatron->GetFineBalance() << " in fines." << endl;
    }
    cout << endl;
}
void patrons::PrintOnePatron() {
    int id;
    cout << "Enter ID: "; cin >> id; cin.ignore(); cout << endl;
    int index = this->FindPatron(id);
    if(index != -1){
        cout << "Name: " << patronlist.at(index)->GetName() << endl;
        cout << "ID: " << patronlist.at(index)->GetID() << endl;
        cout << "# books in possession: " << patronlist.at(index)->GetNumBooksOut() << endl;
        cout << "Fine balance: $" << patronlist.at(index)->GetFineBalance() << endl;
    }
    cout << endl;
}
void patrons::clearpatronslist() {
    vector<patron*>::iterator it = patronlist.begin();
    for(it; it != patronlist.end(); ++it){
        delete *it;
    }
    patronlist.clear();
}
void patrons::loadpatronslist() {
    ifstream fin;
    int patroncount, id, numbooksout;
    string name, sid, snumbooksout, sbalance;
    float balance;
    fin.open("patrons.dat");
    fin >> patroncount; fin.ignore();
    for(int i = 0; i < patroncount; ++i){
        getline(fin, name, ',');
        getline(fin, sid, ',');
        getline(fin, snumbooksout, ',');
        getline(fin, sbalance);
        id = stoi(sid);
        numbooksout = stoi(snumbooksout);
        balance = stof(sbalance);
        patronlist.push_back(new patron(name, id, balance, numbooksout));
    }
    fin.close();
}
void patrons::storepatronslist() {
    ofstream fout;
    vector<patron*>::iterator it = patronlist.begin();
    patron *current;
    fout.open("patrons.dat");
    fout << patronlist.size() << endl;
    for(it; it != patronlist.end(); ++it){
        current = *it;
        fout<<current->GetName()<<","<<current->GetID()<<","<<current->GetNumBooksOut()<<","<<current->GetFineBalance()<<endl;
    }
    fout.close();
}