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

WordList::WordList(Words *wordsList, string *stringList, int noWords)
{
    wordsList = &wordsList;
    stringList = &stringList;
    currIdx = 0; 
    maxLength = noWords * 2;
}

WordList::~WordList() {
    for (int i = 0; i < maxLength; i++) {
        delete wordsList[i];
    }

    delete [] wordsList;
    delete [] stringList;
}

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

void WordList::insertionSort()
{
    // same logic, call before search
    for (int curr = 1; curr < maxLength; curr++) {
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
}

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