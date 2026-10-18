#include <stdbool.h>

bool isMatch(char* s, char* p) {
    if (!*p) return !*s;
    bool match = *s && (*p == *s || *p == '.');
    if (*(p + 1) == '*') 
        return isMatch(s, p + 2) || (match && isMatch(s + 1, p));
    return match && isMatch(s + 1, p + 1);
}