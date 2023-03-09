/*
    Lab: CIS 22B - Honors Project
    Name: Daniel Wong & Ben Hung
    Date: 2/7/23
    Description: A program that match antonyms to common words requested by a user based on a file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Words Structure.
struct Words {
    string *w;
    string *a;
};

// Function Definitions.
Words *readInputFile(string fileName, int &noWords, Words *wordsList, string *stringList);


int main() {
    
    // Printing introduction.
    string fileName;
    cin >> fileName;
        
    Words *wordsList;
    int noWords = 0;
    string *stringList;

    wordsList = readInputFile(fileName, noWords, wordsList, stringList);
    
    return 0;
}

Words *readInputFile(string fileName, int &noWords, Words *wordsList, string *stringList) {
    
    // Creating the object needed to read the file.
    ifstream inputFile;
    
    // Opening the file.
    inputFile.open(fileName.c_str());
    
    // Checking for errors.
    if (inputFile.fail()) {
        cout << "Error opening " << fileName << " for reading." << endl;
        exit(EXIT_FAILURE);
    }
    
    // Getting the number of lines in the file by reading the first line.
    inputFile >> noWords;
    inputFile.ignore();
    
    // Initializing pointer to a dynamically allocated list of Words structures.
    wordsList = new Words[noWords*2];
    stringList = new string[noWords*2];

    for (int i = 0; i < 2*noWords; i+=2) {
        inputFile >> stringList[i];
        inputFile >> stringList[i+1];
        
        wordsList[i].w = &stringList[i];
        wordsList[i].a = &stringList[i+1];
        
        wordsList[i+1].w = &stringList[i+1];
        wordsList[i+1].a = &stringList[i];
        inputFile.ignore();
    }
    
    // Closing the input file.
    inputFile.close();
    
    // Returning the pointer to the dynamically allocated array.
    return wordsList;
}



