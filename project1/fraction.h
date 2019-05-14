/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fraction.h
 * Author: mikeross
 *
 * Created on January 18, 2018, 5:05 PM
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
 public:
  Fraction(int n=0,int d=1);
  ~Fraction(void);
  // rhs == right hand side, as in the right hand side of an operator
  Fraction operator+(Fraction rhs);
  Fraction operator/(Fraction rhs);
  Fraction operator*(Fraction rhs);
  Fraction operator-(Fraction rhs);
  
  
  bool operator==(Fraction rhs);
   bool operator!=(Fraction rhs);
    bool operator<=(Fraction rhs);
    bool operator>=(Fraction rhs);
    bool operator>(Fraction rhs);
 bool operator<(Fraction rhs);
 Fraction operator=(Fraction rhs);
    friend istream &operator>>(istream &,Fraction &f);
    friend ostream &operator<<(ostream &,Fraction f);
 
 
 
private:
int
num,
den; };



#endif /* FRACTION_H */

