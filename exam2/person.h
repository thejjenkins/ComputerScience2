#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class person {
	private:
		int height;
		float weight;
		string name;
		char gender;
		string race;
		string occupation;
	
	public:
		//constructors
		person();
		person(int pheight, float pweight, string pname, char pgender, string prace, string poccupation);
		// mutators
		void setheight(int pheight);
		void setweight(float pweight);
		void setname(string pname);
		void setgender(char pgender);
		void setrace(string prace);
		void setoccupation(string poccupation);
		// accessors
		int displayheight() const;
		float displayweight() const;
		string displayname() const;
		char displaygender() const;
		string displayrace() const;
		string displayoccupation() const;
		void printinfo() const;
};
#endif