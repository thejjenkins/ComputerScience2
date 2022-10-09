#include "person.h"
#include <iostream>
using namespace std;

person::person() : height(0), weight(0.0), name(" "), gender(' '), race(" "), occupation(" ") {}
person::person(int pheight, float pweight, string pname, char pgender, string prace, string poccupation){
	height = pheight;
	weight = pweight;
	name = pname;
	gender = pgender;
	race = prace;
	occupation = poccupation;
}
//mutators
void person::setheight(int pheight){
	height = pheight;
}
void person::setweight(float pweight){
	weight = pweight;
}
void person::setname(string pname){
	name = pname;
}
void person::setgender(char pgender){
	gender = pgender;
}
void person::setrace(string prace){
	race = prace;
}
void person::setoccupation(string poccupation){
	occupation = poccupation;
}
// accessors
int person::displayheight() const {
	return height;
}
float person::displayweight() const {
	return weight;
}
string person::displayname() const {
	return name;
}
char person::displaygender() const {
	return gender;
}
string person::displayrace() const {
	return race;
}
string person::displayoccupation() const {
	return occupation;
}
void person::printinfo() const {
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " << gender << endl;
	cout << "Race: " << race << endl;
	cout << "Height (inches): " << height << endl;
	cout << "Weight (lbs): " << weight << endl;
	cout << "Occupation: " << occupation << endl << endl;
	return;
}
