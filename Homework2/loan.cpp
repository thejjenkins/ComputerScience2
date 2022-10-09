#include "loan.h"
using namespace std;

loan::loan() : loanid(0), bookid(0), patronid(0), duedate(0), loanstatus(" ") {}
loan::loan(int Loanid, int Lbookid, int Lpatronid, int Lduedate, string Lcurrstatus){
    loanid = Loanid;
    bookid = Lbookid;
    patronid = Lpatronid;
    duedate = Lduedate;
    loanstatus = Lcurrstatus;
}
void loan::setloanid(int number) {loanid=number;}
void loan::setbookid(int number) {bookid=number;}
void loan::setpatronid(int number) {patronid=number;}
void loan::setduedate(int number) {duedate=number;}
void loan::setloanstatus(string letter) {loanstatus=letter;}
int loan::getloanid() {return loanid;}
int loan::getbookid() {return bookid;}
int loan::getpatronid() {return patronid;}
int loan::getduedate() {return duedate;}
string loan::getloanstatus() {return loanstatus;}