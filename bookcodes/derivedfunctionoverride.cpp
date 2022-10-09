#include <iostream>
using namespace std;

// base class is computer
class Computer {
public:
   // two public member functions
   void SetComputerStatus(string cpuStatus, string internetStatus) {
      cpuUsage = cpuStatus;
      internet = internetStatus;
   };
   // printstatus will be overridden
   void PrintStatus() {
      cout << "CPU: " << cpuUsage << endl;
      cout << "Internet: " << internet << endl;
   };

protected: // protected data members are only accessible by base class & derived classes
   string cpuUsage;
   string internet;
};

// laptop is derived from computer base class
// class DERIVED : public/private/protected BASE { derived class public and private data member definitions }
class Laptop : public Computer {
public:
   void SetComputerStatus(string cpuStatus, string internetStatus, string wifiStatus) {
      cpuUsage = cpuStatus; // derived class is accessing protected data members of base class
      internet = internetStatus; // derived class is accessing protected data members of base class
      wifiQuality = wifiStatus;
   };
    // This is the overriding function
   void PrintStatus() {
       // This is how to call the base class' function without overriding
      Computer::PrintStatus(); 
      // Base class does not print derived info, so add another line to print the derived class info
      cout << "WiFi: " << wifiQuality << endl;
   };

private:
   string wifiQuality;
};

int main() {
   Laptop myLaptop;

   myLaptop.SetComputerStatus("25%", "connected", "good"); // this constructor accesses protected data members from the computer base class
   myLaptop.PrintStatus(); // this derived class print function does not override the base class print function. See comment in class definition. 

   return 0;
}