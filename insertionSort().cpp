void insertionSort(Words *wordsList, int noWords) {
    for (int curr = 1; curr < noWords*2; curr++) {
        // Make a copy of the current element
        Words temp = wordsList[curr]; 
        
        // Shift elements in the sorted part of the list to make room 
        int walk = curr - 1;
        while(walk >= 0 && *temp.w < *wordsList[walk].w) {
            wordsList[walk + 1] = wordsList[walk];
            walk--;
        }
        
        // Put temp back into the list
        wordsList[walk + 1] = temp;
    }
}