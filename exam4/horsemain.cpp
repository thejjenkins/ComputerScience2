#include <string>
#include <iostream>
#include <vector>
#include "horse.h"
using namespace std;

int main()
{
	vector<animal*> that;

	string breed;
	char spay;
	string ID;
	string comments;
	float weight;
	string name;
	char gender;
	string color;
	
	for(int i = 0; i < 3; i++)
	{
		animal *a;
		cout << "Horse " << i+1 << endl;
		cout << "Breed: ";
		cin >> breed;
		cout << "Weight: ";
		cin >> weight;
		cout << "Name: ";
		cin >> name;
		cout << "Gender(m or f): ";
		cin >> gender;
		cout << "Spayed/Neutered(y or n): ";
		cin >> spay;
		cout << "Registration ID: ";
		cin >> ID;
		cout << "Color: ";
		cin.ignore();
		getline(cin,color);
		cout << "Comments: ";
		cin.ignore();
		getline(cin,comments);
		a = new horse(breed,spay,ID,comments,weight,name,gender,color);
		that.push_back(a);
	}
	cout << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << "horse " << i+1 << endl;
		that.at(i)->print();
		
	}
	cout << endl;
	for(int i = 0; i < 3; i++)
	{
		delete that.at(i);
	}
	that.clear();
	
	return 0;
}
