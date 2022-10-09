#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> garden){
   for(size_t i = 0; i < garden.size(); ++i){
      garden[i]->PrintInfo();
      cout << endl;
   }
}

int main() {
   // TODO: Declare a vector called myGarden that can hold object of type plant pointer
   vector<Plant*> myGarden;
   // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
   //       colorOfFlowers, isAnnual
   string pn, fn, cof;
   int pc, fc;
   string b;
   string input;

   cin >> input;

   while(input != "-1") {
   // TODO: Check if input is a plant or flower
   //       Store as a plant object or flower object
   //       Add to the vector myGarden
   if(input == "plant"){
      cin >> pn >> pc;
      Plant plant;
      plant.SetPlantName(pn);
      plant.SetPlantCost(pc);
      myGarden.push_back(new Plant(plant));
   }
   else{
      cin >> fn >> fc >> b >> cof;
      Flower flower;
      flower.SetPlantName(fn);
      flower.SetPlantCost(fc);
      if(b=="false"){
         flower.SetPlantType(false);
      }
      else{
         flower.SetPlantType(true);
      }
      flower.SetColorOfFlowers(cof);
      myGarden.push_back(new Flower(flower));
   }
   cin >> input;
   }
   // TODO: Call the method PrintVector to print myGarden
   PrintVector(myGarden);

   for (size_t i = 0; i < myGarden.size(); ++i) {
      delete myGarden.at(i);
   }
   
   
   return 0;
}