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
    
    int idx = position-1;
    while (idx >= 0 && *wordsList[idx].getW() == *wordsList[position].getW()) {
        
        cout << ", " << *wordsList[idx].getA();
        idx--;
    }
    
    idx = position +1;
    while (idx < maxLength && *wordsList[idx].getW() == *wordsList[position].getW()) {
        
        cout << ", " << *wordsList[idx].getA();
        idx++;
    }
}

/* 
This function (insertPair) does the following:
- Takes in the strings of word and antonym 
- Puts the strings into the array to be stored

  Function written by: Ben Hung
  Debugged by: Daniel  Wong
*/

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

/* 
This function (insertOne) does the following:
- Takes in an index of the current line from the readInputFile() loop.
- Rearranges Word object located from the index alphabetically in the array of word objects.
  
  Function written by: Ben Hung
  Debugged by: Daniel  Wong
*/

void WordList::insertOne(int curr) {

    // Make a copy of the current element
    Words temp = wordsList[curr]; 

    // Shift elements in the sorted part of the list to make room 
    int walk = curr - 1;

    while(walk >= 0 && *temp.getW() < *wordsList[walk].getW()) {
        wordsList[walk + 1] = wordsList[walk];
        walk--;
    }

    // Put temp back into the list
    wordsList[walk + 1] = temp;
}

/*
This function (binarySearch) does the following:
- Takes in just the target
- Uses the binary search algorithm to efficiently find the string.
- Returns the position/index of the string if found, if not returns -1.

  Function written by: Daniel Wong
  Debugged by: Ben Hung
*/

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

/*
 This function displayArray() does the following: 
 - Prints out the title format.
 - Prints out the sorted alphabetical array of the synonym and proceeding antonyms.
 - Prints out the final format.
 
   Function written by: Ben Hung
   Debugged by: Daniel Wong
*/

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

