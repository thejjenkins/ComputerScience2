#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU\n";
   cout << "a - Add item to cart\n";
   cout << "d - Remove item from cart\n";
   cout << "c - Change item quantity\n";
   cout << "i - Output items' descriptions\n";
   cout << "o - Output shopping cart\n";
   cout << "q - Quit\n";
   return;
}

void ExecuteMenu(char choice, ShoppingCart& customer) {
   switch (choice) {
      case a:
         customer1.AddItem();
         break;
      case d:
         customer1.RemoveItem();
         break;
      case c:
         customer1.ModifyItem();
         break;
      case i:
         customer1.
         break;
      case o:
         break;
      case q:
         break;
      default:
         
   }
}

int main() {
   
   ShoppingCart customer1;
   string cname, cdate;
   char choice;
   bool repeat = true;
   
   cout << "Enter customer's name:\n"; getline(cin, cname);
   cout << "Enter today's date:\n"; getline(cin, cdate);
   customer1=ShoppingCart(cname, cdate);
   cout << "Customer name: " << customer1.GetCustomerName() << endl;
   cout << "Today's date: " << customer1.GetDate() << endl;
   PrintMenu();
   cout << "Choose an option:"; cin>>choice;
   do{
      
   while(choice==('a'||'d'||'c'||'i'||'o')){
      ExecuteMenu(choice, );
   }
   else{
      cout << "Choose an "
   }





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