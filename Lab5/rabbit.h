#include <iostream>
#include <string>
using namespace std;

class Rabbit {
	public:
	//Constructors
	Rabbit();
	Rabbit(string breed, float weight, string name, char gender, char spayorneuter, string regID, string color, string comments);
	//Mutators
	void setbreed(string word);
	void setweight(float weight);
	void setname(string name);
	void setgender(char gender);
	void setspayorneuter(char spayorneuter);
	void setregID(string ID);
	void setcolor(string color);
	void setcomments(string inputcomments);
	//Accessors
	string dispbreed();
	float dispweight();
	string dispname();
	char dispgender();
	char dispspayorneuter();
	string dispregID();
	string dispcolor();
	string dispcomments();
	void printinfo();
	
	private:
	string Breed;
	float Weight;
	string Name;
	char Gender;
	char SpayedorNeutered;
	string registrationID;
	string colordescription;
	string comments;
};