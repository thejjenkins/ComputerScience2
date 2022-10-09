output: main.o patron.o book.o loan.o patrons.o books.o loans.o
	g++ main.o patron.o book.o loan.o patrons.o books.o loans.o -o output

main.o: main.cpp
	g++ -c main.cpp

patron.o: patron.h patron.cpp
	g++ -c patron.cpp

patrons.o: patrons.h patron.h patrons.cpp
	g++ -c patrons.cpp

book.o: book.h book.cpp
	g++ -c book.cpp

books.o: book.h books.h books.cpp
	g++ -c books.cpp

loan.o: loan.h loan.cpp
	g++ -c loan.cpp

loans.o: loan.h loans.h patron.h patrons.h book.h books.h loans.cpp
	g++ -c loans.cpp

clean:
	rm *.o output
