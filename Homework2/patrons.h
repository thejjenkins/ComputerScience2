#ifndef PATRONS_H
#define PATRONS_H
#include <vector>
#include <iostream>
#include <fstream>
#include "patron.h"
using namespace std;

class patrons {
    public:
    patrons() {patroncount = 0;}
    void AddPatron();
    void EditPatron();
    int FindPatron(int id);
    bool SearchPatron(int id);
    void DeletePatron();
    void PayFines();
    void PrintAllPatrons();
    void PrintOnePatron();
    void clearpatronslist();
    void loadpatronslist();
    void storepatronslist();
    friend class loans;

    private:
    int patroncount;
    vector<patron*> patronlist;
};
#endif