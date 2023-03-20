#ifndef WORDLIST_H
#define WORDLIST_H
#include <string>

using std::ostream;
using std::string;

/*
    Wordlist.h file to declare 

    Written by: Ben Hung
    Debugged by: Daniel Wong
*/

class WordList {
    private:

        // Private variables.
        ListNodehead;
        int count;

        // Declare a structure.
        struct Word
        {
            Words wordObj; // The value in this node
            ListNode *next;  // To point to the next node
        };


    public:

        // Destructor and Constructor
        WordList();
        ~WordList();

        // Linked list functions.
        int getCount() const {return count;}
        void insertNode(wordObj);
        void display() const;
        void searchList() const;
};


#endif