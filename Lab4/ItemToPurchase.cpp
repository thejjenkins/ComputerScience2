#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : itemName("none"), itemDescription("none"), itemPrice(0), itemQuantity(0) {}

void ItemToPurchase::SetName(string name) {
   itemName=name;
}

void ItemToPurchase::SetDescription(string description) {
   itemDescription=description;
}

void ItemToPurchase::SetPrice(int price){
   itemPrice=price;
}

void ItemToPurchase::SetQuantity(int quantity) {
   itemQuantity=quantity;
}

string ItemToPurchase::GetName() const {
   return itemName;
}

string ItemToPurchase::GetDescription() const {
   return itemDescription;
}

int ItemToPurchase::GetPrice() const {
   return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
   return itemQuantity;
}

void ItemToPurchase::PrintItemCost() const {
   // FIXME
   return;
}

void ItemToPurchase::PrintItemDescription() const {
   // FIXME
   return;
}
