/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello World";

    return 0;
}

//////////////////////////////////////////////////

/*
This function insertSort does the following: 
    - Takes in the dynamically allocated array of wordsList 
    - Rearranges word from struct Words in an Alphabetical format
    - Updates the struct list afterwards
*/ 

void insertSort(Words *wordsList, int noWords)
{
  
   for (int curr = 1; curr < noWords; curr++)   
     { 
        // make a copy of the current element
        Words temp = wordsList[curr]; 
        
        // shift elements in the sorted part of the list to make room 
        int walk = curr - 1;
        while( walk >= 0 && temp.word > wordsList[walk].word ) //descending
        {
            wordsList[walk + 1] = wordsList[walk];
            walk--;
        }
        
        // put temp back into the list
        wordsList[walk + 1] = temp;
    }
}

//insertSort() ends 
///////////////////////////////////////////////