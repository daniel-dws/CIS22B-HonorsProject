#include "WordList.h"
#include <iostream>    
#include <iomanip>
#include <string>
using namespace std;

 /*
    Implementation file for the WordList class.
    
    Written by: Daniel Wong
    Debugged by: Ben Hung
*/

//Constructor
WordList::WordList(int noWords)
{
    cout << noWords << endl;
    wordsList = new Words[noWords*2];
    stringList = new string[noWords*2];
    currIdx = 0; // no actual Word classes have been inserted into wordsList
    maxLength = noWords * 2;
}

//Overloaded Constructor
WordList::WordList(Words *wordsList, string *stringList, int noWords)
{
    wordsList = wordsList;
    stringList = stringList;
    currIdx = 0; 
    maxLength = noWords * 2;
}

//Destructor
WordList::~WordList() 
{
    delete [] wordsList;
    delete [] stringList;
}

//Getters 
void WordList::getAntonym(int position) {
    cout << *wordsList[position].getA();
}

//insertPair back into display 
void WordList::insertPair(string word, string antonym)
{
    if (currIdx + 2 <= maxLength) {
        stringList[currIdx] = word;
        stringList[currIdx + 1] = antonym;
        
        // call setters to set pointers
        wordsList[currIdx].setW(&stringList[currIdx]);
        wordsList[currIdx].setA(&stringList[currIdx+1]);
        
        wordsList[currIdx+1].setW(&stringList[currIdx+1]);
        wordsList[currIdx+1].setA(&stringList[currIdx]);
        
        
        currIdx += 2;
    }
}

//insertionSort()
void WordList::insertionSort()
{
    //cout << "This part runs" << endl;
    
    // same logic, call before search
    for (int curr = 1; curr < maxLength; curr++) {
        
        //cout << "HI" << endl;
        //cout << maxLength << endl;
        
        //cout << "Here" << endl;
        // Make a copy of the current element
        Words temp = wordsList[curr]; 
        //cout << "Here" << endl;

        // Shift elements in the sorted part of the list to make room 
        int walk = curr - 1;
        //cout << walk << endl;
        while(walk >= 0 && *temp.getW() < *wordsList[walk].getW()) {
            wordsList[walk + 1] = wordsList[walk];
            walk--;
        }

        // Put temp back into the list
        wordsList[walk + 1] = temp;
    }
    
    //cout << "this part also runs" << endl;
}

//binarySearch() 
int WordList::binarySearch(string target) {
    // same logic
    int first = 0,
    last = maxLength - 1,
    middle,
    position = -1;

    // Using while loop until we find or are unable to find the movie.
    while (-1 == position && first <= last) {
        middle = (first + last) / 2;
        if (*wordsList[middle].getW() == target) {
            position = middle;
        }
        else if (*wordsList[middle].getW() > target) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}

//displayArray() 
void WordList::displayArray() {
    
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl; 

    cout << setw(10)  << "word"; 
    cout << setw(10) << "antonym";
    cout << endl; 

    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl;

    // Display each word.
    for (int i = 0; i < maxLength; i++) {
        bool proceed = false;

        // Only printing the word if it is part of the words half (not antonyms).
        for (int j = 0; j < maxLength; j+=2) {
            if (stringList[j].compare(*wordsList[i].getW()) == 0) {
                proceed = true;
            }
        }

        if (proceed == true) {
            cout << right << setw(10) << *wordsList[i].getW();
            cout << "   " << *wordsList[i].getA();
            cout << endl;
        }
    }

    // Display final.
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl;
}

