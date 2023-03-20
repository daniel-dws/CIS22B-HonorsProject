#include "WordList.h"
#include <iostream>    
#include <iomanip>
#include <string>
using namespace std;

/*
    Implementation file for the WordList class.
    
    Written by: Danny Wong
    Debugged by: Ben Hung
*/

//Constructor
WordList::WordList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    count = 0;
}

//Destructor
WordList::~WordList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->next;
    
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    delete head; // delete the sentinel node
}

//insertNode function
void StudentList::insertNode(Word wordObj)
{
  /* Write your code here */
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store dataIn there.
    newNode = new ListNode;
    newNode->word = wordobj;

    // Initialize pointers
    pPre = head;
    pCur = head->next;
   
    // Find location: skip all nodes whose name is less than dataIn's gpa
    while (pCur != NULL && pCur->word.getW() < wordObj.getW())
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    count++;
}

//display function
void WordList::display() const {
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
    for (int i = 0; i < count; i++) {
        bool proceed = false;
        
        // Only printing the word if it is part of the words half (not antonyms).
        for (int j = 0; j < count; j+=2) {
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





