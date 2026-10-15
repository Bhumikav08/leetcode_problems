#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int char_map[256];       // Store last seen index of characters
    int start = 0;           // Left pointer of the window
    int max_len = 0;         // Result tracking
    
    // Initialize map to -1
    for(int i = 0; i < 256; i++) char_map[i] = -1;

    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char c = s[end];
        
        // If character was seen inside current window, move start
        if (char_map[c] >= start) {
            start = char_map[c] + 1;
        }
        
        // Update last seen position
        char_map[c] = end;
        
        // Update maximum length
        int current_len = end - start + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}