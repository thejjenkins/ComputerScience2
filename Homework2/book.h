#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class book {
    public:
    // constructors
    book();
    book(string bauthor, string btitle, int bisbn, int blibIDnum, float bcost, string bcurrstatus);
    // mutators
    void SetAuthor(string words);
    void SetTitle(string words);
    void SetISBN(int number);
    void SetLibIDNum(int number);
    void SetCost(float number);
    void SetCurrStatus(string status);
    // Accessors
    string GetAuthor() const;
    string GetTitle() const;
    int GetISBN() const;
    int GetLibIDNum() const;
    float GetCost() const;
    string GetCurrStatus() const;

    private:
    string author;
    string title;
    int isbn;
    int libIDnum;
    float cost;
    string currstatus;
};
#endif