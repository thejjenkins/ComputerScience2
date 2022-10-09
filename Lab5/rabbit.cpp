#include "rabbit.h"
#include <iostream>

Rabbit::Rabbit() : Breed(" "), Weight(0), Name(" "), Gender(' '), SpayedorNeutered(' '), registrationID(" "), colordescription(" "), comments(" ") {}
Rabbit::Rabbit(string breed, float weight, string name, char gender, char spayorneuter, string regID, string color, string inputcomments) {		
	Breed=breed;
	Weight=weight;
	Name=name;
	Gender=gender;
	SpayedorNeutered=spayorneuter;
	registrationID=regID;
	colordescription=color;
	comments=inputcomments;
}
//Mutators
void Rabbit::setbreed(string word){
	Breed=word;
	return;
};
void Rabbit::setweight(float weight){
	Weight=weight;
	return;
}
void Rabbit::setname(string name){
	Name=name;
	return;
}
void Rabbit::setgender(char gender){
	Gender=gender;
	return;
}
void Rabbit::setspayorneuter(char spayorneuter){
	SpayedorNeutered=spayorneuter;
	return;
}
void Rabbit::setregID(string ID){
	registrationID=ID;
	return;
}
void Rabbit::setcolor(string color){
	colordescription=color;
	return;
}
void Rabbit::setcomments(string inputcomments){
	comments=inputcomments;
	return;
}
//Accessors
string Rabbit::dispbreed(){
	return Breed;
}
float Rabbit::dispweight(){
	return Weight;
}
string Rabbit::dispname(){
	return Name;
}
char Rabbit::dispgender(){
	return Gender;
}
char Rabbit::dispspayorneuter(){
	return SpayedorNeutered;
}
string Rabbit::dispregID(){
	return registrationID;
}
string Rabbit::dispcolor(){
	return colordescription;
}
string Rabbit::dispcomments(){
	return comments;
}
void Rabbit::printinfo(){
	cout << "Breed: " << Breed << endl;
	cout << "Weight: " << Weight << endl;
	cout << "Name: " << Name << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Spayed or Neutered: " << SpayedorNeutered << endl;
	cout << "Registration ID: " << registrationID << endl;
	cout << "Color: " << colordescription << endl;
	cout << "Comments: " << comments << endl;
	return;
}
