#include <iostream>
#include <list>
using namespace std;

int main() {
   list<char> letters;
   char letter;
   unsigned int i;
   int size;
   list<char>::iterator numiterator;
      
   letters.push_back('a');
   letters.push_back('b');
   letters.push_front('c');
   letters.push_front('d');
   
   letters.remove('c'); // removes all elements of this value
   letters.push_back('h');
   letters.pop_back(); // removes last element
   letters.pop_front(); // removes first element
   letters.push_front('e');
   letters.push_back('x');
   letters.push_back('y');
   letters.push_back('z');
   
   cout << "Last letter: " << letters.back() << endl; // returns last element of list

   // for loop using an iterator prevents having to pop elements
   for (numiterator = letters.begin(); numiterator != letters.end(); ++numiterator) { 
      cout << *numiterator << ' ';
   }
   cout << endl;

   // Iterator-based functions: Insert and Erase.
   numiterator = letters.begin();
   cout << *numiterator << " is what numiterator points at. insert g before *numiterator" << endl;
   letters.insert(numiterator, 'g'); // inserts 'g' at element 0, all proceeding elements are shifted forward
   for (numiterator = letters.begin(); numiterator != letters.end(); ++numiterator) { 
      cout << *numiterator << ' ';
   }
   cout << endl;
   numiterator = letters.begin();
   cout << *numiterator << " is what *numiterator points at." << endl;
   ++numiterator; ++numiterator;
   cout << *numiterator << " is what *numiterator points at. Erasing *numiterator." << endl;
   letters.erase(numiterator); // erases the character at element 1
   for(char& listelement : letters) {
      cout << listelement << ' ';
   }
   cout << endl;
   numiterator = letters.end();
   --numiterator; --numiterator;
   cout << *numiterator << " is what numiterator points at. Erase y and z" << endl;
   letters.erase(numiterator, letters.end()); // erases y and z
   for(char& listelement : letters) {
      cout << listelement << ' ';
   }
   cout << endl;

   size = letters.size(); // returns size of list

   // standard for loop using i but the elements have to be popped to access the next one   
   for (i = 0; i < size; ++i) {
      letter = letters.front(); // returns first element of list
      cout << letter << ' ';
      letters.pop_front();
   }
   cout << endl;
   return 0;
}