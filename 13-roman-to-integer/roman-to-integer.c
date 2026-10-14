#include <stdio.h>
#include <string.h>

int getValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int total = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int currentVal = getValue(s[i]);
        
        // Look ahead: if current value is less than next value, subtract it
        if (i + 1 < len && currentVal < getValue(s[i + 1])) {
            total -= currentVal;
        } else {
            total += currentVal;
        }
    }
    return total;
}