/*
This class will use the doubly linked list to insert, pop the numbers. An iteration will be used to do that//





*/

#include<iostream>
#include "DList.cpp"
#include<string>

using namespace std;

#ifndef LARGEINT_H
#define LARGEINT _H

class Largeint{
  private:
    DList<int>db;
    int overflow;
   // bool is_neg;
  public:
    bool is_neg;
    Largeint();
    friend istream & operator >>(istream &in,Largeint &other);
    friend ostream & operator <<(ostream &out, Largeint &other);
    //this function will return the object of the largeint containing the result//
    Largeint operator+(Largeint &obj);
    //a friend func will calculate the result of the substruction//
    friend Largeint operator-(Largeint a,Largeint b);
    bool is_negative_this();
 // Largeint operator =(Largeint other);
    Largeint multiply(Largeint value, const int num);
    Largeint operator*(Largeint &other);
 
    Largeint operator/(Largeint other);
    Largeint operator%(Largeint other);
    bool operator>(Largeint other);
  
};

 
#endif