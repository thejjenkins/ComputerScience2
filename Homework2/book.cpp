#include <string>
#include "book.h"
using namespace std;

// Constructors
book::book() : author(" "), title(" "), isbn(0), libIDnum(0), cost(0), currstatus(" ") {}
book::book(string bauthor, string btitle, int bisbn, int blibIDnum, float bcost, string bcurrstatus) {
    author = bauthor;
    title = btitle;
    isbn = bisbn;
    libIDnum = blibIDnum;
    cost = bcost;
    currstatus = bcurrstatus;
}
// Mutators
void book::SetAuthor(string words){
    author = words;
}
void book::SetTitle(string words){
    title = words;
}
void book::SetISBN(int number){
    isbn = number;
}
void book::SetLibIDNum(int number){
    libIDnum = number;
}
void book::SetCost(float number){
    cost = number;
}
void book::SetCurrStatus(string status){
    currstatus = status;
}
// Accessors
string book::GetAuthor() const {
    return author;
}
string book::GetTitle() const {
    return title;
}
int book::GetISBN() const {
    return isbn;
}
int book::GetLibIDNum() const {
    return libIDnum;
}
float book::GetCost() const {
    return cost;
}
string book::GetCurrStatus() const {
    return currstatus;
}
