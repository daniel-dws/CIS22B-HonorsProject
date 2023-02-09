/*
    Lab: CIS 22B - Honors Project
    Name: Ben Hung
    Date: 2/7/23
    Description: A program that provides antonyms to common words.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Words Structure.
struct Words {
    string word;
    string antonym;
};

// Function Definitions.
Words *readInputFile(string fileName, int &noWords);
int binarySearch(Words *wordsList, int noWords);
void insertionSort(Words *wordsList[], int noWords);
void displayArray(Words *wordsList[], int noWords);

int main() {
    
    // Printing introduction.
    cout << "Welcome! This program will take in a word and try to find its antonym." << endl;
    cout << endl;
    
    // Taking in a word from the user.
    string inputWord;
    cout << "Enter a word: " << endl;
    cin >> inputWord;
    
    // Taking the filename of the input file from the user.
    string fileName;
    cout << "Enter the filename of the input file (include .txt): " << endl;
    cin >> fileName;
    
    // Initializing the dynamically allocated Words list.
    Words *wordsList;
    int noWords = 0;
    wordsList = new Words[noWords];
    
    // Calling readInputFile to read the file to "wordsList".
    wordsList = readInputFile(fileName, noWords);
    
    // Sorting the list using insertion sort.
    insertionSort(wordsList, noWords);
    
    // Searching the dynamically allocated list by calling the binarySearch function.
    int position;
    position = binarySearch(wordsList, noWords);
    
    return 0;
}

// Function Declarations.

/*
 This function (readInputFile) does the following:
    - Takes in the filename of the input file and an integer to set the size of the array.
    - Opens the input file (with validation: exit if file not found).
    - Reads from a input file.
    - Dynamically allocates an array of Words structures.
    - Closes the input file.
    - Returns the pointer that points to the dynamically allocated list of Words structures.
*/

Words *readInputFile(string fileName, int &noWords) {
    
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
    Words *wordsList;
    wordsList = new Words[noWords];

    // Reading the file and storing it in the dynamically allocated array.
    for (int i = 0; i < noWords; i++) {
        inputFile >> wordsList[i].word;
        inputFile.ignore();
        inputFile >> wordsList[i].antonym;
    }
    
    // Closing the input file.
    inputFile.close();
    
    // Returning the pointer to the dynamically allocated array.
    return wordsList;
}

