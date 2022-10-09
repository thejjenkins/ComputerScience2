#ifndef LOANS_H
#define LOANS_H
#include "loan.h"
#include "patrons.h"
#include "books.h"
#include <vector>
using namespace std;

class loans {
    private:
    int loancount;
    vector<loan*> loanlist;

    public:
    loans() {loancount = 0;}
    //void checkinbook(patrons* pats, books* books);
    void checkoutbook(patrons* pats, books* books);
    //void recheckbook(patrons* pats, books* books);
    bool checkdue(int id);
    // void reportlost();
    int findloan(int id);
    // void updateloanstatus();
    void storeloanslist();
    void clearloanslist();
    void loadloanslist();
};
#endif