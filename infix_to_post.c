#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define size 30

int top = -1;
int stack[size];


void push(int item) {
    if (top == size - 1) {
        printf("Stack full\n");
    } else {
        top++;
        stack[top] = item;
    }
}


int pop() {
    if (top == -1) {
        printf("Stack empty\n");
        return -1;
    } else {
        int store = stack[top];
        top--;
        return store;
    }
}


int icp(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 3;
    } else if (c == '^') {
        return 6;
    } else if (c == '(') {
        return 7;
    } else if (c == ')') {
        return 0;
    }
    return -1;
}


int isp(char c) {
    if (c == '+' || c == '-') {
        return 2;
    } else if (c == '*' || c == '/') {
        return 4;
    } else if (c == '^') {
        return 5;
    } else if (c == '(') {
        return 0;
    }
    return -1;
}

// Function to convert infix expression to postfix
void infixtopost(char exp[], char post[]) {
    int i = 0, j = 0;
    char symb, optr;
    push('(');
    strcat(exp, ")");
    
    while (exp[i] != '\0') {
        symb = exp[i];
        if (symb >= '0' && symb <= '9') {
            post[j++] = symb;
        } else if (symb == ')') {
            while (stack[top] != '(') {
                post[j++] = pop();
            }
            pop();
        } else {
            while (icp(symb) <= isp(stack[top])) {
                post[j++] = pop();
            }
            push(symb);
        }
        i++;
    }
    post[j] = '\0';
}

// Function to evaluate the postfix expression
int evaluate(char post[]) {
    int i = 0;
    int op1, op2, value;
    char symb;
    
    while (post[i] != '\0') {
        symb = post[i];
        if (symb >= '0' && symb <= '9') {
            int num = symb - '0';  // Convert char to integer
            push(num);
        } else if (symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '^') {
            op1 = pop();
            op2 = pop();
            switch (symb) {
                case '+': value = op2 + op1; break;
                case '-': value = op2 - op1; break;
                case '*': value = op2 * op1; break;
                case '/': value = op2 / op1; break;
                case '^': value = pow(op2, op1); break;
            }
            push(value);
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[30], post[30];
    
    printf("Enter a numeric infix expression (e.g., 2+3*4+5): ");
    scanf("%[^\n]", exp);

    infixtopost(exp, post);
    
    printf("Postfix expression: %s\n", post);

    int result = evaluate(post);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
