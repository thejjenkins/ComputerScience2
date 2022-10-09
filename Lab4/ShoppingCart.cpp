#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}
ShoppingCart::ShoppingCart(string cname, string cdate) {
    customerName=cname;
    currentDate=cdate;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase newitem){
    cartItems.push_back(newitem);
}
void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for(int i=0; i<cartItems.size(); ++i) {
        if(cartItems[i].GetName()==itemName) {
            cartItems.erase(i);
            found = true;
        }
        if (found == false) {
            cout << "Item not found in cart. Nothing removed." << endl;
        }
    }
}
void ShoppingCart::ModifyItem(ItemToPurchase newitem){
    bool found = false;
    for(int i=0; i<cartItems.size(); ++i){
        if(cartItems[i].GetName==)
    }    
}
int ShoppingCart::GetNumItemsInCart(){
    return ; //FIXME
}
int ShoppingCart::GetCostOfCart(){
    //Determines and returns the total cost of items in cart. has no parameters.
}
void ShoppingCart::PrintTotal(){
    //FIXME
}
string ShoppingCart::PrintDescriptions(){
    //outputs each items description
}