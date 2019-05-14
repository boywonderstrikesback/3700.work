#include <iostream>
#include "fraction.h"


int main(void) {

   Fraction a,b,c;

  cout << "Enter a fraction: ";
  cin >> a;


  cout << "Enter a second fraction: ";
  cin >> b;

  c = a + b;

  cout << "The sum is " << c << endl;

return 0;
}
