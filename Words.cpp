#include "Words.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
    Implementation file for the Words class.
    
    Written by: Danny Wong
    Debugged by: Ben Hung
*/

// Default constructor.
Words::Words()
 {
	w = nullptr;
	a = nullptr;
}

// Overloaded constructor.
Words::Words(string *w, string *a) {
   this->w = w;
   this->a = a;
}
