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
Words *readInputFile(string fileName, int &noWords, Words *wordsList, string *&stringList);
void insertOne(Words *wordsList, int curr);
void displayArray(Words *wordsList, int noWords, string *stringList);
int binarySearch(Words *wordsList, string target, int noWords);

/*
 This function (main) does the following:
    Welcomes user and prompts for the word
    Lower cases all words
    Asks user to repeat program 
    Function written by: Ben Hung
    Debugged by: Daniel Wong
*/
int main() {
    
    // Printing introduction.
    cout << "Welcome! This program will take in a word and try to find its antonym." << endl;
    cout << endl;
    
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
        
        // Initializing dynamically allocated lists and the line count of the input file.
        Words *wordsList;
        int noWords = 0;
        string *stringList;
        
        // Calling readInputFile to read the file to "wordsList".
        wordsList = readInputFile(fileName, noWords, wordsList, stringList);
        
        // Searching the dynamically allocated list by calling the binarySearch function.
        int position;
        position = binarySearch(wordsList, inputWord, noWords);
        
        // Printing result of the search.
        if (position == -1) {
            cout << "\"" << inputWord << "\"" << " is unable to be found." << endl;
        }
        else {
            cout << "\"" << inputWord << "\"" << " has been found! Its antonym is " << *wordsList[position].a;
            
            // Printing other matches.
            int idx = position-1;
            while (idx >= 0 && *wordsList[idx].w == *wordsList[position].w) {
                cout << ", " << *wordsList[idx].w;
                idx--;
            }
            
            idx = position +1;
            while (idx < noWords*2 && *wordsList[idx].w == *wordsList[position].w) {
                
                cout << ", " << *wordsList[idx].a;
                idx++;
            }
            
            cout << "." << endl;
        }
        
        // Displaying the array if its less than 25 lines.
        if (noWords < 25) {
            displayArray(wordsList, noWords, stringList);
        }
        
        // Asking user if they would like to repeat the program.
        count++;
        cout << "\nWould you like to repeat?" << endl;
        cin >> repeat;
        
        // Changing the input to all lowercase characters.
        for (int i = 0; i < repeat.length(); i++) {
            repeat[i] = tolower(repeat[i]);
        }
    }
    
    return 0;
}

// Function Declarations.

/*
 This function (readInputFile) does the following:
    - Takes in the filename of the input file, an integer to set the size of the array, a pointer to a string list, and a pointer to
        an array of Words structures.
    - Opens the input file (with validation: exit if file not found).
    - Reads from a input file.
    - Dynamically allocates an array of strings.
    - Dynamically allocates an array of Words structures (points to the string array).
    - Closes the input file.
    - Returns the pointer that points to the dynamically allocated list of Words structures.
    
    Function written by: Daniel Wong
    Debugged by: Ben Hung
*/
Words *readInputFile(string fileName, int &noWords, Words *wordsList, string *&stringList) {
    
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
        
        // Sorting the new item using insertion sort.
        insertOne(wordsList, i);
        insertOne(wordsList, i+1);
        
        inputFile.ignore();
    }
    
    // Closing the input file.
    inputFile.close();
    
    // Returning the pointer to the dynamically allocated array.
    return wordsList;
}

/*
 This function (insertOne) does the following: 
    - Takes in the dynamically allocated array of wordsList and the index of the structure it should sort.
    - Rearranges the structure from the array of Words structures in an alphabetical format.
    - Updates the struct list afterwards.
    
    Function written by: Ben Hung
    Debugged by: Danny Wong
*/ 
void insertOne(Words *wordsList, int curr) {

    // Make a copy of the current element
    Words temp = wordsList[curr];

    // Shift elements in the sorted part of the list to make room 
    int walk = curr - 1;

    while (walk >= 0 && *temp.w < *wordsList[walk].w) {
        wordsList[walk + 1] = wordsList[walk];
        walk--;
    }

    // Put temp back into the list
    wordsList[walk + 1] = temp;
}

/*
 This function displayArray() does the following: 
    - Takes in the dynamically allocated array of wordsList.
    - Prints out the title format.
    - Prints out the sorted alphabetical array of the synonym and proceeding antonyms.
    - Prints out the final format.
    
    Function written by: Ben Hung
    Debugged by: Daniel Wong
*/
void displayArray(Words *wordsList, int noWords, string *stringList) {
    
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
    for (int i = 0; i < noWords*2; i++) {
        bool proceed = false;
        
        // Only printing the word if it is part of the words half (not antonyms).
        for (int j = 0; j < noWords*2; j+=2) {
            if (stringList[j].compare(*wordsList[i].w) == 0) {
                proceed = true;
            }
        }
        
        if (proceed == true) {
            cout << right << setw(10) << *wordsList[i].w;
            cout << "   " << *wordsList[i].a;
            cout << endl;
        }
    }

    // Display final.
    cout << setw(0)  << "==========   ";
    cout << setw(0)  << "==========   ";
    cout << endl;
}

/*
 This function (binarySearch) does the following:
    - Takes in a dynamically allocated array, the target, and the size of the array.
    - Uses the binary search algorithm to efficiently find a string.
    - Returns the position/index of the string if found, if not returns -1.
    
    Function written by: Daniel Wong
    Debugged by: Ben Hung
*/
int binarySearch(Words *wordsList, string target, int noWords) {
    
    // Declaring variables needed for binary search.
    int first = 0,
    last = noWords*2 - 1,
    middle,
    position = -1;
    
    // Using while loop until we find or are unable to find the movie.
    while (-1 == position && first <= last) {
        middle = (first + last) / 2;
        if (*wordsList[middle].w == target) {
            position = middle;
        }
        else if (*wordsList[middle].w > target) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}
