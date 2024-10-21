#include <iostream>
#include "cmath"
using namespace std;

string input; double yy;
void clearSC( );

int main() {
   cout << "Square Root Calculator\n\n";
   cout << "redesigned by 113611092 Àj¦ö¸Û\n\n";

   while(1) {
      cout << "Enter a number(type \"exit\" or \"quit\" to leave):";
      cin >> input;

      if(input == "quit" || input == "exit") break;
      if(input == "cls") {
         clearSC(); continue;
      }

      yy = stoi(input);                         //convert string to double
      if(yy < 0){
         cout << "Invalid number!\n";
         continue;
      }

      cout << "SQRT of ";
      if(yy < 100) cout << " ";
      if(yy < 10) cout << " ";
      cout << yy << " = " << sqrt(yy) << endl;
   }
   cout << "Bye !\n";
   return 0;
}

void clearSC() {
   char xxx[]= "\033[2J\033[1;1H";              // "\e[2J\e[1;1H";
   cout << xxx << endl;                         //ESCape sequence seems NOT work
   try {
    system("CLS");
   }catch(exception e){
      for(int i=0; i < 38; i++) cout << "\n";
   }
}
