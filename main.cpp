




#include <iostream>
#include "Largeint.h"

using namespace std;
void printMenu();

int main() {
 Largeint l,l2,l6;
 int choice;


 cout<<"\nOperations allowed on the Large integer calculation. WARNING: This program only calculates positive numbers"
      <<"\nPlease enter the number of your choice and press return.\n\n"; 
 
 
 
 cout<<"Enter number: ";
 cin>>l;

 cout<<"Enter number: ";
 cin>>l2;


printMenu();
cin>>choice;
   while ( choice != 6 )
   {

       switch ( choice )
      {
   
         case 1 : l6=l+l2;
                  break;
    
         case 2 : l6=l-l2;
                  break;

         case 3 : l6=l*l2;
                  break;
                   
         case 4 : l6=l/l2;
                  break;
                     
         case 5 : l6=l%l2;
                  break;
        default:cout<<"Wrong Input"<<endl;
                  break;

 
 
 
 
}
cout<<endl<<"The result is: "<<l6<<endl;
cin>>choice;
   }
   
 
}

void printMenu ()
{
   

   cout<<"\n1: Enter 1 to do the addition of the two positive lagre integer.";
   cout<<"\n2: Enter 2 to do the substraction of the two positive lagre integer.";
   cout<<"\n3: Enter 3 to do the mutiplication of the two positive lagre integer.";
   cout<<"\n4: Enter 4 to do the divition of the two positive lagre integer.";
   cout<<"\n5: Enter 5 to do modulus of the two positive lagre integer.";
   cout<<"\n6: Exit"<<endl;
  
  
  
}