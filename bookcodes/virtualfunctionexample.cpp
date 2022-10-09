#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This program illustrates runtime polymorphism. Polymorphism refers to a function taking on different applications.
// Runtime polymorphism is when the application of the function is decided during runtime as opposed to compile time.
class Business {
public:
   void SetName(string busName) {
      name = busName;
   }

   void SetAddress(string busAddress) {
      address = busAddress;
   }
    // the virtual function of the base class
    // notice the keyword virtual before the function
   virtual string GetDescription() const {
      return name + " -- " + address;
   }

protected:
   string name;
   string address;
};

class Restaurant : public Business {
public:
   void SetRating(int userRating) {
      rating = userRating;
   }

   int GetRating() const {
      return rating;
   }
    // the override function of the derived class
    // notice the keyword override in the function
   string GetDescription() const override {
      return name + " -- " + address +
         "\n  Rating: " + to_string(rating);
   }

private:
   int rating;
};

int main() {
   unsigned int i;
   vector<Business*> businessList; // the vector contains business pointers. Business pointers can be business class or the derived restaurant class.
   Business* businessPtr; // declaring a business class pointer
   Restaurant* restaurantPtr; // declaring a derived restaurant class pointer

   businessPtr = new Business;
   businessPtr->SetName("ACME");
   businessPtr->SetAddress("4 Main St");

   restaurantPtr = new Restaurant;
   restaurantPtr->SetName("Friends Cafe");
   restaurantPtr->SetAddress("500 2nd Ave");
   restaurantPtr->SetRating(5);

   businessList.push_back(businessPtr); // vector businessList can contain business class & derived restaurant class
   businessList.push_back(restaurantPtr); // vector businessList can contain business class & derived restaurant class

   for (i = 0; i < businessList.size(); ++i) {
      cout << businessList.at(i)->GetDescription() << endl; // This is where runtime polymorphism happens. The program does not know which GetDescription() function to use until it finds out whether the current object is a business class or derived restaurant class.
   }

   return 0;
}