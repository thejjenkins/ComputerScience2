#include "patron.h"
using namespace std;

patron::patron() : name(" "), id(0), finebalance(0), numbooksout(0) {}
patron::patron(string Name, int ID, float fineBalance, int numBooksOut) {
    name = Name;
    id = ID;
    finebalance = fineBalance;
    numbooksout = numBooksOut;
}
// Mutators
void patron::SetName(string words){
    name = words;
}
void patron::SetID(int num){
    id = num;
}
void patron::SetFineBalance(float num){
    finebalance = num;
}
void patron::SetNumBooksOut(int num){
    numbooksout = num;
}
// Accessors
string patron::GetName() const{
    return name;
}
int patron::GetID() const{
    return id;
}
float patron::GetFineBalance() const {
    return finebalance;
}
int patron::GetNumBooksOut() const {
    return numbooksout;
}