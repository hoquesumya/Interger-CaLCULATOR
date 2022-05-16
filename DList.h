#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Sumya Hoque                                   */        
/* Date: March 2 , 2021                                    */        
/* Purpose:  generic unsorted doubly linked list class - header file including a struct and a nested class for the iteraor   */ /***************************************************************/

#ifndef DLIST_H
#define DLIST_H

template <class T>
struct node
{
    T info;
    node *next;
    node *back;
};


template <class T>
class DList 
{   
   private:
      node<T> *first; 
      node<T>*last;
       
   public:
      //Constructor 
      DList();
      // Destructor
      ~DList();
      //Copy constructor
      DList ( const DList<T> & other);
      //Overloaded =  
      const DList<T> & operator= (const DList<T> & other);
      //Returns the current length of list
      int getLength();
      //Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item in its proper position
      void insertItem_front(T item);
      //If list is not empty and parameter item is in the list. If list is //empty or item is not in the list, prints error message
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Prints all items in the list. Prints error message if list is empty.
      void printList();
      //Copies a list
      void copy (const DList<T> & other);
      //Destroys the list 
      void destroy();
      //insertitem from back
      void insertItem_back(T item);
      //printing in reverse//
      void printback();

      int getlength();
      void intialize();
      
      
      
  
      //this class is a iteraor class that has operator ++,operator--,operator !=,and a constructor//
      class iterator{
        public:
  //constructor//
  iterator(node<T>*n){
    current=n;
  }
  //operator overloading++//
  iterator &operator++(int){
      current=current->next;
      return *this;
   }
   //operator overloading --//
  iterator &operator--(int){
     current=current->back;
     return *this;
   }
   //operator overloading  of the pointer derefernce//
  T & operator*(){
      return current->info;
  }
  //operator overloading !=//
  bool operator!=(const iterator &r){
    return this->current!=r.current;
  }
   bool operator==(const iterator &r){
    return this->current==r.current;
  }
  private:
    node<T> *current;
    
};
        
  
      //set node to first
      iterator begin() const;
      //set node to last
      iterator end() const;
      //set node to list->next Null to avoid segmentation error//
      iterator endofList()const;
      //set node to first->back to avoid segmentation error//
      iterator beginofList()const;
      
};


#endif




