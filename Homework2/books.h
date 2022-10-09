#ifndef BOOKS_H
#define BOOKS_H
#include "book.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class books {
    private:
    int bookcount;
    vector<book*> booklist;

    public:
    books() {bookcount = 0;}
    friend class loans;
    void AddBook();
    void EditBook();
    int FindBook(int libidnum);
    void DeleteBook();
    void PrintOneBook();
    void PrintAllBooks();
    void storebookslist();
    void clearbookslist();
    void loadbookslist();
};
#endif