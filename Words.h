#ifndef WORDS_H
#define WORDS_H
#include <string>

using std::ostream;
using std::string;

class Words {
   private:
      string *w;
      string *a;

   public:
   
      Words();
      Words(string *w, string *a);
      
      void setW(string *w) { this->w = w; }
      void setA(string *a) {this->a = a; }
      string* getW() { return w; }
      string* getA() { return a; }
};

#endif
