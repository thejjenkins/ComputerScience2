#include <iostream>
using namespace std;

#include "rabbit.h"

int main() {
	Rabbit *rabbitobject;
	rabbitobject = new Rabbit[6];
	for(int i=0; i<6; ++i){
		string word;
		float weight;
		string name;
		char gender;
		char spayorneuter;
		string ID;
		string color;
		string inputcomments;
		
		cout << "Enter breed:\n";
		cin.ignore();
		getline(cin, word);
		rabbitobject[i].setbreed(word);
		
		cout << "Enter weight:\n"; cin >> weight;
		rabbitobject[i].setweight(weight);
		cin.ignore();
		
		cout << "Enter name:\n"; getline(cin, name);
		rabbitobject[i].setname(name);
		
		cout << "Enter gender (m/f):\n"; cin >> gender;
		rabbitobject[i].setgender(gender);
		
		cout << "Is the rabbit spayed or neutered? (y/n):\n"; cin >> spayorneuter;
		rabbitobject[i].setspayorneuter(spayorneuter);
		cin.ignore();
		
		cout << "Enter registration ID:\n"; getline(cin, ID);
		rabbitobject[i].setregID(ID);
		
		cout << "Enter color description:\n"; getline(cin, color);
		rabbitobject[i].setcolor(color);
		
		cout << "Enter any comments:\n"; getline(cin, inputcomments);
		rabbitobject[i].setcomments(inputcomments);
	}
	
	for(int i=0; i<6; ++i){
		cout << "Breed of rabbit " << i+1 << ": " << rabbitobject[i].dispbreed() << endl;
		cout << "Weight of rabbit " << i+1 << ": " << rabbitobject[i].dispweight() << endl;
		cout << "Name of rabbit " << i+1 << ": " << rabbitobject[i].dispname() << endl;
		cout << "Gender of rabbit " << i+1 << ": " << rabbitobject[i].dispgender() << endl;
		cout << "Spayed or neutered of rabbit " << i+1 << ": " << rabbitobject[i].dispspayorneuter() << endl;
		cout << "Registration ID of rabbit " << i+1 << ": " << rabbitobject[i].dispregID() << endl;
		cout << "Color of rabbit " << i+1 << ": " << rabbitobject[i].dispcolor() << endl;
		cout << "Comments about rabbit " << i+1 << ": " << rabbitobject[i].dispcomments() << endl;
	}

	delete[] rabbitobject;
	
	return 0;
}