#ifndef LOAN_H
#define LOAN_H
#include <string>
using namespace std;

class loan {
    public:
    // constructors
    loan();
    loan(int Loanid, int Lbookid, int Lpatronid, int Lduedate, string Lcurrstatus);
    // mutators
    void setloanid(int number);
    void setbookid(int number);
    void setpatronid(int number);
    void setduedate(int number);
    void setloanstatus(string status);
    // accessors
    int getloanid();
    int getbookid();
    int getpatronid();
    int getduedate();
    string getloanstatus();

    private:
    int loanid;
    int bookid;
    int patronid;
    int duedate;
    string loanstatus;
};
#endif