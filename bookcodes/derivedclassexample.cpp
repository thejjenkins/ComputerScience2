#include <iostream>
using namespace std;

// Base class is vehicle
class Vehicle {
   public:
   // two public member functions
      void SetSpeed(int speedToSet) {
         speed = speedToSet;
      }

      void PrintSpeed() {
         cout << speed;
      }
    // one private data member
   private:
      int speed;
};

// Base class is carriage
class Carriage {
   public:
   // two public member functions
      void SetSeats(int seatsToSet) {
         seats = seatsToSet;
      }

      void PrintSeats() {
         cout << seats << " seats in wagon";
      }
    // one private data member
   private:
      int seats;
};

// class DERIVEDCLASS : public BASECLASS, public BASECLASS {...}
// The derived class can use all public member functions from base class that is separated by a comma
class AnimalDrawnCarriage : public Vehicle, public Carriage {
   public:
      void SetAnimal(string animalToSet) {
         animal = animalToSet;
      }

      void PrintAnimalSpeed() {
         cout << animal << " speed: ";
         PrintSpeed();
      }

   private:
      string animal;
};

int main() {
   AnimalDrawnCarriage wagon;

   wagon.SetSpeed(10); // derived class is accessing a vehicle member function and vehicle private data member
   wagon.SetSeats(4); // derived class is accessing a carriage member function and carriage private data member
   wagon.SetAnimal("Camel"); // derived class is being used

   wagon.PrintAnimalSpeed(); // derived class is accessing a vehicle member function
   cout << endl;
   wagon.PrintSeats(); // derived class is accessing a carriage member function

   return 0;
}