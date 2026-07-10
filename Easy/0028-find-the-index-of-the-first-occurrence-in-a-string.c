int strStr(char* haystack, char* needle) {
    // Handle edge cases where the needle is empty
    if (strlen(needle) == 0) return 0;
    if (strlen(haystack) < strlen(needle)) return -1;

  // i is running through haystack until it gets to the end where there wouldn't be enough letters to even contain needle
    for(int i = 0; i <= strlen(haystack) - strlen(needle); i++) {
        int j = 0; // for each letter set j to 0 <- this is how we always look through needle from its start letter

        while(j < strlen(needle) && haystack[i + j] == needle[j]) { // run through needle, while it and haystack are still the same letters
            j++; //go to the next needle letter 
        }

        if(j == strlen(needle)) { //if we get to the end of needle, declared by j = the total of needles length
            return i; // return where the original for loop was at in haystack when the while loop finished
        }
    }
    return -1;
}
