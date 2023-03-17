#ifndef WORDS_H
#define WORDS_H
#include <string>

using std::ostream;
using std::string;

/*
    Words.h file to declare 
    
    Written by: Ben Hung
    Debugged by: Daniel Wongs
*/

class Words {
    private:
    
        // Private variables.
        string *w;
        string *a;

    public:
    
        // Default and overloaded constructor.
        Words();
        Words(string *w, string *a);
        
        // Setters and getters.
        void setW(string *w) { this->w = w; }
        void setA(string *a) {this->a = a; }
        string* getW() { return w; }
        string* getA() { return a; }

};

#endif
