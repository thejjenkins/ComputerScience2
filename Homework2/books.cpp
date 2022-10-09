#include "book.h"
#include "books.h"
using namespace std;

void books::AddBook() {
    string bauthor, btitle;
    int bisbn, blibIDnum;
    float bcost;
    string bcurrstatus;
    book* newbook;
    cout << "Enter author: "; getline(cin, bauthor);
    cout << "Enter title: "; getline(cin, btitle);
    cout << "Enter ISBN: "; cin >> bisbn; cin.ignore();
    cout << "Enter library ID number: "; cin >> blibIDnum; cin.ignore();
    cout << "Enter book cost: "; cin >> bcost; cin.ignore();
    cout << "Enter current status (i/o): "; cin >> bcurrstatus; cin.ignore();
    newbook = new book(bauthor, btitle, bisbn, blibIDnum, bcost, bcurrstatus);
    booklist.push_back(newbook);
    cout << endl;
}
void books::EditBook() {
    int bookid;
    cout << "Enter library ID number: "; cin >> bookid; cin.ignore(); cout << endl;
    int index = this->FindBook(bookid);
    if(index != -1){
        int choice;
        cout << "Edit book cost = 1\nEdit current status = 2\nQuit = 0\n";
        cout << "Choice: "; cin >> choice;
        if(choice == 1){
            float newcost;
            cout << endl << "New cost: "; cin >> newcost;
            booklist.at(index)->SetCost(newcost);
            cout << endl;
        }
        else if(choice == 2){
            string newbookstatus;
            cout << endl << "New status (i/o): "; cin >> newbookstatus;
            booklist.at(index)->SetCurrStatus(newbookstatus);
            cout << endl;
        }
        else{
            cout << "Returning to main menu." << endl << endl;
        }
    }
}
int books::FindBook(int libidnum) {
    for(int i = 0; i < booklist.size(); ++i){
        if((booklist.at(i))->GetLibIDNum() == libidnum){
            return i;
        }
    }
    cout << "Book not found." << endl;
    return -1;
}
void books::DeleteBook() {
    int bookid;
    cout << "Enter library ID number: "; cin >> bookid; cin.ignore();
    int index = this->FindBook(bookid);
    if(index != -1){
        booklist.erase(booklist.begin()+index);
    }
    cout << "Deleted." << endl;
}
void books::PrintOneBook() {
    int bookid;
    cout << "Enter library ID number: "; cin >> bookid; cout << endl;
    int index = this->FindBook(bookid);
    if(index != -1){
        cout << "Author: " << booklist.at(index)->GetAuthor() << endl;
        cout << "Title: " << booklist.at(index)->GetTitle() << endl;
        cout << "ISBN: " << booklist.at(index)->GetISBN() << endl;
        cout << "Library ID number: " << booklist.at(index)->GetLibIDNum() << endl;
        cout << "Book cost: " << booklist.at(index)->GetCost() << endl;
        cout << "Current status: " << booklist.at(index)->GetCurrStatus() << endl;
    }
    cout << endl;
}
void books::PrintAllBooks() {
    vector<book*>::iterator it = booklist.begin();
    for(it; it != booklist.end(); ++it){
        cout << "\"" << (*it)->GetTitle() << "\"" << " by " << (*it)->GetAuthor() << ". ISBN: " << (*it)->GetISBN() << ". Library ID number: " << (*it)->GetLibIDNum() << ". Cost: $" << (*it)->GetCost() << ". Status: " << (*it)->GetCurrStatus() << endl;
    }
    cout << endl;
}
void books::storebookslist() {
    ofstream fout;
    vector<book*>::iterator it = booklist.begin();
    book *current;
    fout.open("books.dat");
    fout << booklist.size() << endl;
    for(it; it != booklist.end(); ++it){
        current = *it;
        fout<<current->GetAuthor()<<","<<current->GetTitle()<<","<<current->GetISBN()<<","<<current->GetLibIDNum()<<","<<current->GetCost()<<","<<current->GetCurrStatus()<<endl;
    }
    fout.close();
}
void books::clearbookslist() {
    vector<book*>::iterator it = booklist.begin();
    for(it; it != booklist.end(); ++it){
        delete *it;
    }
    booklist.clear();
}
void books::loadbookslist() {
    ifstream fin;
    int totalbooks, isbn, libidnum;
    string bauthor, btitle, bisbn, blibidnum, bcost, currstatus;
    float cost;
    fin.open("books.dat");
    fin >> totalbooks; fin.ignore();
    for(int i = 0; i < totalbooks; ++i){
        getline(fin, bauthor, ',');
        getline(fin, btitle, ',');
        getline(fin, bisbn, ',');
        getline(fin, blibidnum, ',');
        getline(fin, bcost, ',');
        getline(fin, currstatus);
        isbn = stoi(bisbn);
        libidnum = stoi(blibidnum);
        cost = stof(bcost);
        booklist.push_back(new book(bauthor, btitle, isbn, libidnum, cost, currstatus));
    }
    fin.close();
}