#include <fstream>
#include <iostream>
#include "patron.h"
#include "patrons.h"
#include "book.h"
#include "books.h"
#include "loan.h"
#include "loans.h"
using namespace std;

int main() {
    patrons* listofpatrons = new patrons;
    books* listofbooks = new books;
    loans* listofloans = new loans;
    int choice = -1;

    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
    
    listofpatrons->loadpatronslist();
    listofbooks->loadbookslist();
    listofloans->loadloanslist();

    cout << "+----------------------------------------------------------+" << endl;
    cout << "|             Computer Science and Engineering             |" << endl;
    cout << "|             CSCE 1040 - Computer Science II              |" << endl;
    cout << "|   James Jenkins    jaj0303    jamesjenkins2@my.unt.edu   |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << endl;
    cout << "                    WELCOME TO LIBRARY                      " << endl << endl;
    
    while(choice != 0){
        cout << "******************** MAIN MENU ********************\n";
        cout << "Patron operations = 1\n";
        cout << "Book operations = 2\n";
        cout << "Loan operations = 3\n";
        cout << "Quit = 0\n";
        cout << "Choice: "; cin >> choice; cin.ignore(); cout << endl;
        switch(choice){
            case 1:
                int choice2;
                cout << "******************** PATRONS MENU ********************\n";
                cout << "Add patron = 1\n";
                cout << "Edit patron = 2\n";
                cout << "Delete patron = 3\n";
                cout << "Pay fines = 4\n";
                cout << "Print one patron = 5\n";
                cout << "Print all patrons = 6\n";
                cout << "Quit = 0\n";
                cout << "Choice: "; cin >> choice2; cin.ignore(); cout << endl;
                switch(choice2){
                    case 1:
                        listofpatrons->AddPatron();
                        break;
                    case 2:
                        listofpatrons->EditPatron();
                        break;
                    case 3:
                        listofpatrons->DeletePatron();
                        break;
                    case 4:
                        listofpatrons->PayFines();
                        break;
                    case 5:
                        listofpatrons->PrintOnePatron();
                        break;
                    case 6:
                        listofpatrons->PrintAllPatrons();
                        break;
                    default:
                        break;
                }
            break;
            case 2:
                int choice3;
                cout << "******************** BOOKS MENU ********************\n";
                cout << "Add book = 1\n";
                cout << "Edit book = 2\n";
                cout << "Delete book = 3\n";
                cout << "Print one book = 4\n";
                cout << "Print all books = 5\n";
                cout << "Quit = 0\n";
                cout << "Choice: "; cin >> choice3; cin.ignore(); cout << endl;
                switch(choice3){
                    case 1:
                        listofbooks->AddBook();
                        break;
                    case 2:
                        listofbooks->EditBook();
                        break;
                    case 3:
                        listofbooks->DeleteBook();
                        break;
                    case 4:
                        listofbooks->PrintOneBook();
                        break;
                    case 5:
                        listofbooks->PrintAllBooks();
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                int choice4;
                cout << "******************** LOANS MENU ********************\n";
                cout << "Check out a book = 1\n";
                cout << "Check in a book = n/a\n";
                cout << "Recheck a book = n/a\n";
                cout << "Report lost = n/a\n";
                cout << "Update loan status = n/a\n";
                cout << "Quit = 0\n";
                cout << "Choice: "; cin >> choice4; cout << endl;
                switch(choice4){
                    case 1:
                        listofloans->checkoutbook(listofpatrons, listofbooks);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    

    listofpatrons->storepatronslist();
    listofpatrons->clearpatronslist();
    listofbooks->storebookslist();
    listofbooks->clearbookslist();
    listofloans->storeloanslist();
    listofloans->clearloanslist();
    delete listofbooks;
    delete listofloans;
    delete listofpatrons;
    return 0;
}