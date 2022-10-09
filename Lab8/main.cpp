#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printmenu() {
   cout << "MENU\n";
   cout << "a - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\n";
}

int main() {
   vector<int> jersey;
   vector<int> rating;
   int jerseynum, playerrating;
   char choice;
   bool repeat=true;
   
   for (int i=1; i<=5; ++i) {
      cout << "Enter player " << i << "'s jersey number:\n"; cin >> jerseynum;
      cout << "Enter player " << i << "'s rating:\n"; cin >> playerrating;
      jersey.push_back(jerseynum);
      rating.push_back(playerrating);
      cout << endl;
   }
   cout << "ROSTER\n";
   for(unsigned int i=0;i<jersey.size();++i) {
      cout << "Player " << i+1 << " -- Jersey number: " << jersey[i] << ", Rating: " << rating[i] << endl;
   }
   cout << endl;
   printmenu();
   while(repeat) {
      cout << "Choose an option:\n";
      cin >> choice;
      if(choice=='a') {
         cout << "Enter a new player's jersey number:\n"; cin >> jerseynum;
         cout << "Enter the player's rating:\n"; cin >> playerrating;
         jersey.push_back(jerseynum);
         rating.push_back(playerrating);
         cout << endl;
      }
      if(choice=='d') {
         cout << "Enter a jersey number:\n"; cin >> jerseynum;
         for(unsigned int i=0;i<jersey.size();++i) {
            if(jersey[i]==jerseynum) {
               jersey.erase(jersey.begin()+i);
               rating.erase(rating.begin()+i);
            }
         }
      }
      if(choice=='u') {
         cout << "Enter a jersey number:\n"; cin >> jerseynum;
         for(unsigned int i=0;i<jersey.size();++i) {
            if(jersey[i]==jerseynum) {
               cout << "Enter a new rating for player:\n"; cin >> playerrating;
               rating[i]=playerrating;
            }
         }
         cout << endl;
      }
      if(choice=='r') {
         
         cout << "Enter a rating:\n"; cin >> playerrating;
         cout << endl << "ABOVE " << playerrating << endl;
         for(unsigned int i=0;i<jersey.size();++i) {
            if(rating.at(i)>playerrating) {
               cout << "Player " << i+1 << " -- Jersey number: " << jersey[i] << ", Rating: " << rating[i] << endl;
               
            }
         }
         cout << endl;
      }
      if(choice=='o') {
         cout << "ROSTER\n";
         for(unsigned int i=0;i<jersey.size();++i) {
            cout << "Player " << i+1 << " -- Jersey number: " << jersey[i] << ", Rating: " << rating[i] << endl;
         }
         cout << endl;
      }
      if(choice!='q') {
         printmenu();
      }
      if(choice=='q') {
         repeat = false;
      }
   }
   
   return 0;
}
