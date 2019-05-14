#include "fraction.h"
#include <iostream>


using namespace std;
int main(void) {
  
  
  Fraction fy,fx,px,py,cx,cy,Area;
  
  cout << "Enter two fractions: ";
  cin >> fx >> fy;

cx=fx;
cy=fy;
 do {
      px=cx;
      py=cy;

      cin >> cx>> cy;

      Area=Area+(px*cy-py*cx);
   } while(cx!=fx or cy!=fy);

Area=Area/2;
cout<<"total Area: "<<Area<<endl;

  return 0;
}


