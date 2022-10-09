// problem 13
#include "person.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<person> people(4);
	vector<person>::iterator it = people.begin();
	int height;
	float weight;
	string name;
	char gender;
	string race;
	string occupation;
	
	for(int i = 0; i<4; ++i) {
		cout << "Enter name: "; getline(cin, name);
		//cin.ignore();
		cout << "Enter gender: "; cin >> gender;
		cin.ignore();
		cout << "Enter race: "; getline(cin, race);
		cout << "Height (inches): "; cin >> height;
		cout << "Weight (lbs): "; cin >> weight;
		cin.ignore();
		cout << "Occupation: "; getline(cin, occupation);
		
		person currentperson(height, weight, name, gender, race, occupation);
		people.at(i) = currentperson;
	}
	/*for(&person temp : people) {
		cout << temp.printinfo();
	}*/
	for(it; it != people.end(); ++it){
		(*it).printinfo();
	}
	/*for(int i = 0; i<people.size(); ++i){
		people.at(i).printinfo();
	}*/
	people.clear();
	return 0;
}