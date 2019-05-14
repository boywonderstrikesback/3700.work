#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

using namespace std;


class Fraction {
 public:
  Fraction(int n=0, int d=1);
   ~Fraction(void);

	Fraction operator+(Fraction rhs);
	Fraction operator-(Fraction rhs);
	Fraction operator*(Fraction rhs);
	Fraction operator/(Fraction rhs);
	Fraction operator=(Fraction rhs);

	bool operator==(Fraction rhs);
	bool operator!=(Fraction rhs);
	bool operator>=(Fraction rhs);
	bool operator<=(Fraction rhs);
	bool operator<(Fraction rhs);
	bool operator>(Fraction rhs);
	

	friend istream &operator>>(istream &,Fraction &);
	friend ostream &operator<<(ostream &,Fraction &);


  private:
   int
     num,
     den;
};
#endif

