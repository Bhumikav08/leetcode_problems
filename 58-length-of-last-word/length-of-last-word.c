#include <string.h>

int lengthOfLastWord(char* s) {
    // Edge case: check for NULL or empty string
    if (s == NULL || s[0] == '\0') return 0;

    int i = strlen(s) - 1;
    
    // Step 1: Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    int length = 0;
    // Step 2: Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}