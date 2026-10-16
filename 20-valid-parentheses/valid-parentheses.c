#define MAX_SIZE 10000

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = malloc(sizeof(Stack));
    s->top = -1; // Initialize top
    return s;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char c) {
    if (s->top < MAX_SIZE - 1) 
        s->data[++(s->top)] = c;
}

char pop(Stack* s) {
    if (!isEmpty(s)) return s->data[s->top--];
    return ' ';
}

bool isValid(char* s) {
    Stack* st = createStack();
    int i = 0;
    while (s[i] != '\0') { // Correct null check
        char c = s[i++];
        if (c == '(' || c == '{' || c == '[') {
            push(st, c);
        } else {
            char topChar = pop(st);
            if ((c == ')' && topChar != '(') || 
                (c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[')) {
                free(st);
                return false;
            }
        }
    }
    bool result = isEmpty(st);
    free(st);
    return result;
}