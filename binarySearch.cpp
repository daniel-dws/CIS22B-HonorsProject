int binarySearch(Words *wordsList, string target, int noWords) {
    
    // Declaring variables needed for binary search.
    int first = 0,
    last = noWords - 1,
    middle,
    position = -1;
    
    // Using while loop until we find or are unable to find the movie.
    while (-1 == position && first <= last) {
        middle = (first + last) / 2;
        if (*wordsList[middle].w== target) {
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


