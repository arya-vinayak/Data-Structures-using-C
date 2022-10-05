
/*
Convert an expression from Infix to prefix using stack and evaluate the prefix expression

A Prefix expression, is a mathematical notation in which operators precede their
operands, in contrast to the more common infix expression, in which operators are placed
between operands.

Prefix/postfix notation is especially popular for its innate ability to express the
intended order of operations without the need for parentheses and other precedence rules,
as are usually employed with infix notation. That is why the calculators we use may internally
be using prefix expressions to evaluate your input expression.

In this week’s lab exercise you will need to write functions for the following:
1. Given an infix expression “infix_exp” of length n, convert it to an prefix
expression “prefix_exp”
2. Given a prefix expression “prefix_exp”, evaluate it to get an integer result.

Your task is to complete 2 functions:
Void infix_to_prefix(char infix[SIZE], char prefix[SIZE], int n); // store the prefix
expression in the string prefix
int evaluatePrefix(char prefix[SIZE], int n); // returns evaluation result of prefix

Consider the following order for operator precedence:
1. ^
2. /, *
3. +, -

You are free to use the boilerplate code mailed to you or you can write one abiding
the input and output format provided below. Do not keep unnecessary print statements.

Use appropriate data structure(s) and complete the task such that your code should
be complete, meaning it should be able to give the right output for any valid input, handling
all the edge cases.

Input Format

Each test case will have 1 line as input.
The line contains an integer n and a string(character array) “infix_exp” of size n with
a space separating them.
1 <= n <= 100
Each character in infix_exp will be either 0-9 or one of ^, /, +, -, ) or (
Each input will always be vaild. No need to check if input it invalid.

Output Format

The output should:
1. The equivalent prefix expression which is a string(character array)
2. The evaluation result after processing the prefix expression which is an integer.

The output needs to be in a single line and space separated. 

Testcase 1
Input

3 2+5
Output

+25 7
Testcase 2
Input

7 2+3*5+6
Output

++2*356 23
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *operators;
    int top;
    int capacity;

} Stack;

int init(Stack *s, int size) {

    s->capacity = size;
    s->operators = (char*)malloc(sizeof(char)*size);
    s->top = -1;
    return s->top;
}

int isFull(Stack *s)
{

    if (s->top == s->capacity - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Stack *s)
{

    if (s->top == -1)
        return 1;
    else
        return 0;
}

char peek(Stack *s) {

    if(!isEmpty(s))
    {
         return s->operators[s->top];
    }
    else 
    {
        return '!';
    }
}


int push(Stack *s, char operator)
{

    if (isFull(s)) 
    {
        printf("Overflow\n");
    }
    else
    {
        s->top++;
        s->operators[s->top] = operator;
    }
    return s->top;

}

char pop(Stack *s)
{
    char e;
    if (!isFull(s))
    {
        e = s->operators[s->top];
        s->top--;
        return e;
    }
    return '\0';
}

int precedence(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case ')': return 0;
        default: printf("Invalid\n");         
    }
}

void convert(Stack *s, char *expression)
{
    char postfix[s->capacity];
    int ptop = 0, inserted = 0;
    for (int i = 0; i < strlen(expression); i++)
    {
        //printf("exp %c\n", expression[i]);
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
        {
            postfix[ptop] = expression[i];
            ptop++;
        }
        else if (expression[i] == ')') 
            {
                s->top = push(s, expression[i]);
            } 
        else if (expression[i] == '(') 
        {
            while (!isEmpty(s) && (peek(s) != ')'))
            {   
                postfix[ptop] = peek(s);
                ptop++;
                s->top--;
            }
            if (isEmpty(s)) printf("Invalid\n");
            else s->top--;

        }
        

        else if (precedence(expression[i])) 
        {   
            //printf("operator %c\n", expression[i]);
            if(isEmpty(s) || (precedence(expression[i]) >= precedence(peek(s)))) 
            {
                //printf("pushing to empty stack\n");
                s->top = push(s, expression[i]);
            }
            else if (precedence(expression[i]) < precedence(peek(s))) 
            {
                //printf("else if\n");
                while (!isEmpty(s) && (precedence(expression[i]) < precedence(peek(s)))) 
                {
                    if (expression[i] != '^') 
                    {
                        //printf("else if while\n");
                        postfix[ptop] = pop(s);
                        ptop++;
                    }
                    else break;
                    
                }
                s->top = push(s, expression[i]);
            }
        }
    }

    while(!isEmpty(s)) {
      postfix[ptop] = pop(s);
      ptop++;
    }

    printf("%s\n", postfix);
}

int main()
{
    int size;
    printf("Size of expression: ");
    scanf("%d", &size);
    char *expression = (char*)malloc(sizeof(char)*size);
    Stack s;
    s.top = init(&s, size);
    printf("Enter the expression: ");
    scanf("%s", expression);
    //printf("%s", expression);
    convert(&s, expression);
    return 0;
}
