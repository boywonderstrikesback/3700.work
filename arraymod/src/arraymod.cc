#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int readArray(int integerArray[], int maxNumElements); 
int sumArray(int integerArray[], int numElements);
void displayArray(int integerArray[], int numElements);


int main(int nNumberofArgs, char* pszArgs[]){
// input the loop count



cout << "This program sums values entered "
<< "by the user\n";
cout << "Terminate the loop by entering "
<< "a negative number\n"; cout << endl;


int inputValues[128];
int numberOfValues = readArray(inputValues, 128);
// now output the values and the sum of the values displayArray(inputValues, numberOfValues);
cout << "The sum is "
<< sumArray(inputValues, numberOfValues) << endl;
// wait until user is ready before terminating program // to allow the user to see the program results
cout << "Press Enter to continue..." << endl; cin.ignore(10, '\n');
cin.get();
return 0; }


int readArray(int integerArray[], int maxNumElements){

int numberOfValues; for(numberOfValues = 0;
numberOfValues < maxNumElements; numberOfValues++)
{
// fetch another number
int integerValue;
cout << "Enter next number: "; cin >> integerValue;
// if it's negative... if (integerValue < 0)
        {
            // ...then exit
break; }
// ... otherwise store the number
// into the storage array integerArray[numberOfValues] = integerValue;
}
// return the number of elements read
return numberOfValues; }

void displayArray(int integerArray[], int numElements) {
cout << "The value of the array is:" << endl; for (int i = 0; i < numElements; i++)
{
cout << i << ": " << integerArray[i] << endl;
}
    cout << endl;
}
int sumArray(int integerArray[], int numElements){
    int accumulator = 0;
for (int i = 0; i < numElements; i++){
accumulator += integerArray[i];
}
    return accumulator;
}
    

