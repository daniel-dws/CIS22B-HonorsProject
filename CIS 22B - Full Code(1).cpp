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
    string word;
    string antonym;
};

// Function Definitions.
Words *readInputFile(string fileName, int &noWords);
int binarySearch(Words *wordsList, string target, int noWords);
void insertionSort(Words *wordsList, int noWords);
void displayArray(Words *wordsList, int noWords);

int main() {
    
    // Printing introduction.
    cout << "Welcome! This program will take in a word and try to find its antonym." << endl;
    cout << endl;
    
    // Taking in a word from the user.
    string inputWord;
    cout << "Enter a word: ";
    cin >> inputWord;
    cout << endl; 
    
    // Taking the filename of the input file from the user.
    string fileName;
    cout << "Enter the filename of the input file (include .txt): ";
    cin >> fileName;
    cout << endl;
    
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
    position = binarySearch(wordsList, inputWord, noWords);
    
    // Printing result of the search.
    if (position == -1) {
        cout << "\"" << inputWord << "\"" << " is unable to be found." << endl;
    }
    else {
        cout << "\"" << inputWord << "\"" << " has been found! Its antonym is " << wordsList[position].antonym << "." << endl;
    }
    
    // Displaying the array if its less than 25 lines.
    if (noWords < 25) {
        displayArray(wordsList, noWords);
    }
    
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

/*
 This function (binarySearch) does the following:
    - Takes in a dynamically allocated array, the target, and the size of the array.
    - Uses the binary search algorithm to efficiently find a string.
    - Returns the position/index of the string if found, if not returns -1.
*/
int binarySearch(Words *wordsList, string target, int noWords) {
    
    // Declaring variables needed for binary search.
    int first = 0,
    last = noWords - 1,
    middle,
    position = -1;
    
    // Using while loop until we find or are unable to find the movie.
    while (-1 == position && first <= last) {
        middle = (first + last) / 2;
        if (wordsList[middle].word == target) {
            position = middle;
        }
        else if (wordsList[middle].word > target) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}


/*
 This function (insertSort) does the following: 
    - Takes in the dynamically allocated array of wordsList 
    - Rearranges word from struct Words in an alphabetical format
    - Updates the struct list afterwards
*/ 

void insertionSort(Words *wordsList, int noWords) 
{
    
    for (int curr = 1; curr < noWords; curr++) {
        // Make a copy of the current element
        Words temp = wordsList[curr]; 
        
        // Shift elements in the sorted part of the list to make room 
        int walk = curr - 1;
        while(walk >= 0 && temp.word < wordsList[walk].word) {
            wordsList[walk + 1] = wordsList[walk];
            walk--;
        }
        
        // Put temp back into the list
        wordsList[walk + 1] = temp;
    }
}

/*
 This function displayArray() does the following: 
    - Takes in the dynamically allocated array of wordsList 
    - Prints out the title format
    - Prints out the sorted alphabetical array of the synonym and proceeding antonyms
    - Prints out the final format
*/

void displayArray(Words *wordsList, int noWords) {
    
    // Display starting title.
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
    for (int i = 0; i < noWords; i++) {
        cout << right << setw(10) << wordsList[i].word; 
        cout << "   " << wordsList[i].antonym;
        cout << endl;
    }

    // Display final.
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl; 
}