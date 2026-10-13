#include <stdlib.h>
#include <limits.h>

typedef struct {
    int s[30001];
    int idx;
    int min;
} MinStack;

MinStack* minStackCreate() {
    MinStack *ptr = calloc(1, sizeof(MinStack));
    ptr->idx = 0;
    ptr->min = INT_MAX;
    return ptr;
}

void minStackPush(MinStack* obj, int val) {
    if (val <= obj->min) {
        obj->s[obj->idx++] = obj->min;
        obj->min = val;
    }
    obj->s[obj->idx++] = val;
}

void minStackPop(MinStack* obj) {
    if (obj->s[--obj->idx] == obj->min)
        obj->min = obj->s[--obj->idx];
}

int minStackTop(MinStack* obj) {
    return obj->s[obj->idx - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;     
}

void minStackFree(MinStack* obj) {
    free(obj); 
}