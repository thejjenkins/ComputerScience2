#ifndef PATRON_H
#define PATRON_H
#include <string>
using namespace std;

class patron {
    public:
    //Constructors
    patron();
    patron(string Name, int ID, float fineBalance, int numBooksOut);
    //Mutators
    void SetName(string words);
    void SetID(int num);
    void SetFineBalance(float num);
    void SetNumBooksOut(int num);
    //Accessors
    string GetName() const;
    int GetID() const;
    float GetFineBalance() const;
    int GetNumBooksOut() const;

    private:
    string name;
    int id;
    float finebalance;
    int numbooksout;
};
#endif