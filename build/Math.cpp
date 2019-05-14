#include <iostream>

using namespace std;

int main()
{
    int myInt = 100;
    

    myInt = myInt / 10; //myInt is now 10
    myInt = myInt * 10; //myInt is back to 100
    myInt = myInt + 50; //myInt is up to 150
    myInt = myInt - 50; //myInt is back to where it started

    myInt = myInt + 100 * 2; // myInt is now 300 because multiplication takes precedence over addition
    myInt = (myInt + 100) * 2; // myInt is now 800 because we have changed the precedence using parentheses

    myInt -= 10; // myInt is now 790 because this line is the short-hand for myInt = myInt - 10;
    myInt = myInt % 100; // myInt is now 90 because % is modulus operator

    cout << myInt << endl;

    cin.get();//Taking one character or waiting after displaying output
    
    return 0; //Passing message to the Operating System saying that the code has been successfully execute. 
}
