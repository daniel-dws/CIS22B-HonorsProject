#include "Words.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Words::Words()
 {
	w = nullptr;
	a = nullptr;
}
Words::Words(string *w, string *a) {
   this->w = w;
   this->a = a;
}
