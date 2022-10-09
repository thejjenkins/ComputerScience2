#include <map>
#include <string>
#include <iostream>

using namespace std;

int main () {
   string studentName;
   double studentGrade;

   map<string, double> studentGrades;

   // Students' grades (pre-entered)
   studentGrades.emplace("Harry Rawlins", 84.3);
   studentGrades.emplace("Stephanie Kong", 91.0);
   studentGrades.emplace("Shailen Tennyson", 78.6);
   studentGrades.emplace("Quincy Wraight", 65.4);
   studentGrades.emplace("Janine Antinori", 98.2);
   
/* My code is next. Lab simply asked to read in a student name and grade (without checking studentGrades.count(studentName)),
 output students current grade, update grade with studentGrade, and output the new grade.
 */

   getline(cin, studentName);
   cin>>studentGrade;
   cout << studentName << "'s original grade: " << studentGrades.at(studentName) << endl;
   studentGrades.erase(studentName);
   studentGrades.emplace(studentName, studentGrade);
   cout << studentName << "'s new grade: " << studentGrades.at(studentName) << endl;


   return 0;
}
