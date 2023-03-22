/*
    Lab: CIS 22B - Honors Project Version2 (Classes)
    Name: Daniel Wong & Ben Hung
    Date: 2/7/23
    Description: A program that match antonyms to common words requested by a user based on a file using Classes.
*/

#include "Words.h"
#include "WordList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Definitions.
WordList *readInputFile(string fileName, int &noWords);
/*
 This function (main) does the following:
    - Welcomes user and prompts for the word
    - Lower cases all words
    - Asks user to repeat program 

    Function written by: Ben Hung
    Debugged by: Daniel Wong
*/

int main() {
    
    // Printing introduction.
    cout << "Welcome! This program will take in a word and try to find its antonym." << endl;
    cout << endl;
    
    //Loop to repeat program based on yes/no
    string repeat = "no";
    int count = 0;
    while (repeat == "yes" || count == 0) {
        
        // Taking in a word from the user.
        string inputWord;
        cout << "Enter a word: ";
        cin >> inputWord;
        cout << endl; 
        
        // Changing the word to all lowercase characters.
        for (int i = 0; i < inputWord.length(); i++) {
            inputWord[i] = tolower(inputWord[i]);
        }
        
        // Taking the filename of the input file from the user.
        string fileName;
        cout << "Enter the filename of the input file (include .txt): ";
        cin >> fileName;
        cout << endl;
        
        int noWords = 0;
        
        // Calling readInputFile to read the file to "wordsList".
        WordList *wordsList = readInputFile(fileName, noWords);
        
        // Sorting the list using insertion sort.
        wordsList->insertionSort();
        
        // Searching the dynamically allocated list by calling the binarySearch function.
        int position;
        position = wordsList->binarySearch(inputWord);
        
        cout << "Binary Sort works" << endl;
        
        // Printing result of the search.
        if (position == -1) {
            cout << "\"" << inputWord << "\"" << " is unable to be found." << endl;
        }
        else {
            cout << "\"" << inputWord << "\"" << " has been found! Its antonym is ";
            wordsList->getAntonym(position);
            cout << "." << endl;
        }
        
        // Displaying the array if its less than 25 lines.
        if (noWords < 25) {
            //displayArray(wordsList, noWords, stringList);
            wordsList->displayArray();
        }
        
        // Asking user if they would like to repeat the program.
        count++;
        cout << "\nWould you like to repeat? (yes/no)" << endl;
        cin >> repeat;
        
        // Changing the input to all lowercase characters.
        for (int i = 0; i < repeat.length(); i++) {
            repeat[i] = tolower(repeat[i]);
        }
    }

    return 0;
}

/*
 This function (readInputFile) does the following:
    - Takes in the filename of the input file, an integer to set the size of the array, a pointer to a string list, and a pointer to
        an array of Words objects.
    - Opens the input file (with validation: exit if file not found).
    - Reads from a input file.
    - Dynamically allocates an array of strings.
    - Dynamically allocates an array of Words objects (points to the string array).
    - Closes the input file.
    - Returns the pointer that points to the dynamically allocated list of Words objects.
    
    Function written by: Daniel Wong
    Debugged by: Ben Hung
*/

WordList *readInputFile(string fileName, int &noWords) {
    
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
    
    WordList *obj = new WordList(noWords);
    
    string word;
    string antonym;

    for (int i = 0; i < 2*noWords; i+=2) {
        inputFile >> word;
        inputFile >> antonym;
        
        obj->insertPair(word, antonym);
        
        inputFile.ignore();
    }
    
    // Closing the input file.
    inputFile.close();
    
    return obj;
}
