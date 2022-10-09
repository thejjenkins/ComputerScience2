#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write method to create and output all permutations of the list of names.
void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList) {
   if(nameList.empty()){
      for(unsigned int i = 0; i < permList.size(); ++i){
         cout << permList[i];
         if(i < (permList.size()-1)){
            cout << ", ";
         }        
      }
      cout << endl;
   }
   else{
      for(unsigned int i = 0; i < nameList.size(); ++i){
         vector<string> newpermList = permList;
         newpermList.push_back(nameList[i]);
         vector<string> newnameList = nameList;
         newnameList.erase(newnameList.begin()+i);
         PrintAllPermutations(newpermList, newnameList);
      }
   }
}

int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read in a list of names; stop when -1 is read. Then call recursive method.
   cin >> name;
   while(name != "-1"){
      nameList.push_back(name);
      cin >> name;
   }
   PrintAllPermutations(permList, nameList);
   
   return 0;
}
