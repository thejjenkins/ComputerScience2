#include "loan.h"
#include "loans.h"
#include "patron.h"
#include "patrons.h"
#include "book.h"
#include "books.h"
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

// void loans::checkinbook(patrons* pats, books* books) {
//     int newloanid;
//     cout << "Enter loan ID: "; cin >> newloanid;
//     int index = this->findloan(newloanid);
//     if(index != -1){
//         if(this->checkdue(newloanid)){

//         }
//     }
// }
void loans::checkoutbook(patrons* pats, books* books) {
    time_t now = time(0);
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    int newloanid, newpatronid, booklibidnum, newduedate;
    string newloanstatus;
    patron* pat;
    book* book;
    cout << endl << "Enter patron ID: "; cin >> newpatronid;
    if(pats->SearchPatron(newpatronid)){
        int index = pats->FindPatron(newpatronid);
        if(pat[index].GetNumBooksOut()<6){ //another check: if any books are overdue, don't allow to borrow
            cout << "Enter loan ID: "; cin >> newloanid; cin.ignore();
            cout << "Enter book's library ID number: "; cin >> booklibidnum; cin.ignore();
            newloanstatus = "u";
            newduedate = now + 864000;
            loan* newloan = new loan(newloanid, booklibidnum, newpatronid, newduedate, newloanstatus);
            loanlist.push_back(newloan);
        }
    }
}
/*void loans::recheckbook() {
    int newloanid, duedate, days, hours, minutes, seconds;
    time_t now = time(0);
    struct tm nowlocal;
    nowlocal = *localtime(&now);
    cout << "Enter loan ID: "; cin >> newloanid; cin.ignore();
    int index = this->findloan(newloanid);
    if(index != -1){
        int timediff = loanlist.at(index)->getduedate() - now;
        days = timediff%86400; hours = (timediff-days*86400)%24; minutes = (timediff-days*86400-hours*60)%60; seconds = (timediff-days*86400-hours*60-minutes*60)%60;
        if(timediff>0){
            cout << "Book is due in " << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds." << endl;
        }
        else if(duedate<0){
            cout << "Book is overdue." << endl;
        }
    }
}*/
bool loans::checkdue(int id) {
    int booksoverdue = 0, newloanid, duedate, days, hours, minutes, seconds;
    time_t now = time(0);
    struct tm nowlocal;
    nowlocal = *localtime(&now);
    int index = this->findloan(id);
    if(index != -1){
        int timediff = loanlist.at(index)->getduedate() - now;
        if(timediff>0){
            return false;
        }
        else{
            return false;
        }
    }
}
// void loans::reportlost()
int loans::findloan(int id) {
    for(int i = 0; i < loanlist.size(); ++i){
        if((loanlist.at(i))->getloanid() == id){
            return i;
        }
    }
    cout << "Loan not found." << endl;
    return -1;
}
// void loans::updateloanstatus()
void loans::storeloanslist(){
    ofstream fout;
    vector<loan*>::iterator it = loanlist.begin();
    loan *current;
    fout.open("loans.dat");
    fout << loanlist.size() << endl;
    for(it; it != loanlist.end(); ++it){
        current = *it;
        fout<<current->getloanid()<<","<<current->getbookid()<<","<<current->getpatronid()<<","<<current->getduedate()<<","<<current->getloanstatus()<<endl;
    }
    fout.close();
}
void loans::clearloanslist(){
    vector<loan*>::iterator it = loanlist.begin();
    for(it; it != loanlist.end(); ++it){
        delete *it;
    }
    loanlist.clear();
}
void loans::loadloanslist(){
    ifstream fin;
    int totalloans, currentloanid, currentbookid, currentpatronid, currentduedate;
    string loanstatus, loanid, bookid, patronid, duedate;
    fin.open("loans.dat");
    fin >> totalloans; fin.ignore();
    for(int i = 0; i < totalloans; ++i){
        getline(fin, loanid, ',');
        getline(fin, bookid, ',');
        getline(fin, patronid, ',');
        getline(fin, duedate, ',');
        getline(fin, loanstatus);
        currentloanid = stoi(loanid);
        currentbookid = stoi(bookid);
        currentpatronid = stoi(patronid);
        currentduedate = stoi(duedate);
        loanlist.push_back(new loan(currentloanid, currentbookid, currentpatronid, currentduedate, loanstatus));
    }
    fin.close();
}