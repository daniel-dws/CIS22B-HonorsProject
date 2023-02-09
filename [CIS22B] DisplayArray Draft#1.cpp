#include <iostream>
#include <iomanip> 
using namespace std;
void displayArray(Words* wordsList[], int noWords);

int main()
{
    displayArray();
}

/////////////////////////////////////////////
/*
`This function displayArray() does the following: 
    - Takes in the dynamically allocated array of wordsList 
    - Prints out the title format
    - Prints out the sorted alphabetical array of the synonym and proceeding antonyms
    - Prints out the final format
*/

void displayArray(Words* wordsList[], int noWords) {
    
    //Display Starting Title
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl; 
    
    cout << setw(10)  << "word"; 
    cout << setw(10) << "antonym";
    cout << endl; 
    
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    
    //Display each word
    for (int i = 0; i < n < i++) {
        cout << list[i].word << "   " << list[i].antonym;
        cout << endl;
    }

    //Display Final
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl; 
}

//////////////////////////////////////////