#ifndef WORDLIST_H
#define WORDLIST_H

#include "Words.h"
#include <string>
using namespace std;

/*
    Wordlist.h file to declare 
    Written by: Ben Hung
    Debugged by: Daniel Wong
*/

//Constructor
class WordList {
    private:
        Words *wordsList;
        string *stringList;
        
        int maxLength;
        int currIdx;

    public: 
        WordList(int noWords);
        WordList(Words *wordsList, string *stringList, int noWords);
}

#endif