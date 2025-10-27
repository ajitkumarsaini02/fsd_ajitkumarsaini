#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

// Stack structure
struct stack {
    char item[STACKSIZE];
    int top;
} S;

// Stack functions
void Initialize() {
    S.top = -1;
}

int IsEmpty() {
    return (S.top == -1);
}

void push(char x) {
    if (S.top == STACKSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    S.top++;
    S.item[S.top] = x;
}

char pop() {
    if (IsEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    char x = S.item[S.top];
    S.top--;
    return x;
}

// Function to check balanced parentheses
void balanceParenthesis(char exp[]) {
    Initialize();
    int i = 0, flag = 0;

    while (exp[i] != '\0') {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (!IsEmpty()) {
                pop();
            } else {
                flag = 1; // Extra closing parenthesis
                break;
            }
        }
        i++;
    }

    if (IsEmpty()) {
        if (flag == 1)
            printf("Invalid Expression\n");
        else
            printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }
}

// Main function
int main() {
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);

    balanceParenthesis(exp);

    return 0;
}
