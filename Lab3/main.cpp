#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   ItemToPurchase Item1;
   ItemToPurchase Item2;
   string itemName;
   int itemPrice, itemQuantity, i=1;
   int totalcost, total1, total2;
   
   cout << "Item " << i << endl; ++i;
   cout << "Enter the item name:\n"; getline(cin, itemName);
   cout << "Enter the item price:\n"; cin >> itemPrice;
   cout << "Enter the item quantity:\n"; cin >> itemQuantity;
   cin.ignore();
   
   Item1.SetName(itemName);
   Item1.SetPrice(itemPrice);
   Item1.SetQuantity(itemQuantity);
   
   cout << endl << "Item " << i << endl;
   cout << "Enter the item name:\n"; getline(cin, itemName);
   cout << "Enter the item price:\n"; cin >> itemPrice;
   cout << "Enter the item quantity:\n"; cin >> itemQuantity;
   
   Item2.SetName(itemName);
   Item2.SetPrice(itemPrice);
   Item2.SetQuantity(itemQuantity);
   
   total1=Item1.GetPrice()*Item1.GetQuantity();
   total2=Item2.GetPrice()*Item2.GetQuantity();
   totalcost = total1 + total2;
   
   cout << endl << "TOTAL COST" << endl;
   cout << Item1.GetName() << " " << Item1.GetQuantity() << " @ $" << Item1.GetPrice() << " = $" << total1 << endl;
   cout << Item2.GetName() << " " << Item2.GetQuantity() << " @ $" << Item2.GetPrice() << " = $" << total2 << endl << endl;
   cout << "Total: $" << totalcost << endl;


   
   return 0;
}