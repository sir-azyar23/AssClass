#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define SIZE 100

struct CharStack {
    char stack[SIZE];
    int top;
} charStack;

struct DoubleStack {
    double stack[SIZE];
    int top;
} doubleStack;

void initCharStack() {
    charStack.top = -1;
}

void initDoubleStack() {
    doubleStack.top = -1;
}

// Push to character stack
void pushChar(char item) {
    if (charStack.top >= SIZE - 1) {
        printf("Character Stack Overflow\n");
    } else {
        charStack.stack[++charStack.top] = item;
    }
}

// Pop from character stack
char popChar() {
    if (charStack.top == -1) {
        printf("Character Stack Underflow\n");
        return '\0';
    } else {
        return charStack.stack[charStack.top--];
    }
}

// Push to double stack
void pushDouble(double item) {
    if (doubleStack.top >= SIZE - 1) {
        printf("Double Stack Overflow\n");
    } else {
        doubleStack.stack[++doubleStack.top] = item;
    }
}

// Pop from double stack
double popDouble() {
    if (doubleStack.top == -1) {
        printf("Double Stack Underflow\n");
        return -1;
    } else {
        return doubleStack.stack[doubleStack.top--];
    }
}

// Precedence of operators
int precedence(char op) {
    if (op == '^') 
    return 3;
    if (op == '*' || op == '/') 
    return 2;
    if (op == '+' || op == '-') 
    return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    initCharStack();
    int i = 0, j = 0;

    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(infix[i]);
        } else if (infix[i] == ')') {
            while (charStack.stack[charStack.top] != '(') {
                postfix[j++] = popChar();
            }
            popChar();  
        } else {
            while (charStack.top != -1 && precedence(charStack.stack[charStack.top]) >= precedence(infix[i])) {
                postfix[j++] = popChar();
            }
            pushChar(infix[i]);
        }
        i++;
    }

    while (charStack.top != -1) {
        postfix[j++] = popChar();
    }
    postfix[j] = '\0';
}

// Evaluate postfix expression
double evaluatePostfix(char* postfix, double values[]) {
    initDoubleStack();
    int i = 0;

    while (postfix[i]) {
        if (isalpha(postfix[i])) {
            pushDouble(values[postfix[i] - 'a']);
        } else {
            double b = popDouble();
            double a = popDouble();
            switch (postfix[i]) {
                case '+': pushDouble(a + b); break;
                case '-': pushDouble(a - b); break;
                case '*': pushDouble(a * b); break;
                case '/': pushDouble(a / b); break;
                case '^': pushDouble(pow(a, b)); break;
            }
        }
        i++;
    }
    return popDouble();
}

int main() {
    char infix[SIZE], postfix[SIZE];
    double values[26] = {0};  

    printf("Enter an infix expression (use variables a-z): ");
    scanf("%s", infix);

    for (int i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i])) {
            printf("Enter value for %c: ", infix[i]);
            scanf("%lf", &values[infix[i] - 'a']);
        }
    }

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    double result = evaluatePostfix(postfix, values);
    printf("Result: %.2lf\n", result);

    return 0;
}
