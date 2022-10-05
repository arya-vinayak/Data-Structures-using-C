#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct stack
{
    int top;
    int capacity;
    char* stackelements;
};
typedef struct stack Stack;

void init_stack(Stack* S,int size);
void push(Stack* S,char ele);
char pop(Stack* S);
char peep(Stack* S);
int ipre(char ch);
int spre(char ch);
int isEmpty(Stack* S);
int isFull(Stack* S);

int isEmpty(Stack* S)
{
    return (S->top == -1);
}
int isFull(Stack* S)
{
    return (S->top == S->capacity-1);
}


void infixtopostfix(Stack* S,char* exp);



void init_stack(Stack* S,int size)
{
    S->top = -1;
    S->stackelements = (char*)malloc(size*sizeof(char));
    S->capacity = size;
}

void push(Stack* S,char ele)
{
    if(isFull(S))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        S->top++;
        S->stackelements[S->top] = ele;
    }
}

char pop(Stack* S)
{
    if(isEmpty(S))
    {
        printf("Stack Underflow\n");
        return '$';
    }
    else
    {
        char ele = S->stackelements[S->top];
        S->top--;
        return ele;
    }
}

char peep(Stack* S)
{
    
    
    return S->stackelements[S->top];
    
}

int isOperand(char ele)
{
    if((ele >= 'a' && ele <= 'z') || (ele >= 'A' && ele <= 'Z'))
    {
        return 1;

    }
    return 0;
}

int ipre(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 3;
        case '^':
        return 6;
        default:
        return -1;
    }
}

int spre(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 4;
        case '^':
        return 5;
        default:
        return -1;
    }
}

void infixtopostfix(Stack* S,char* exp)
{
    char ch;
    int k = 0;
    int i = 0;
    
    int len = strlen(exp);
    char postfix[len];
    
    push(S,'#');
    while((ch=exp[i]) != '\0')
    {
        if(ch == '(')
        {
            push(S,ch);
        }
        else if(isOperand(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == ')')
        {
            while( S->stackelements[S->top] != '(')
            {
                ch = pop(S);
                postfix[k++] = ch;
            }
            char ele = pop(S);
        }
        else
        {
            while(ipre(ch) <= spre(S->stackelements[S->top]))
            {
                postfix[k++] = pop(S);
            }
            push(S,ch);
        }
        i++;
    }
    while(S->stackelements[S->top] != '#')
    {
        postfix[k++] = pop(S);

    }

    postfix[k] = '\0';
    printf("the final postfix expression is :\n");
    printf("%s",postfix);
}

int main()
{
    Stack S;
    char str[30] = "a+b*(c^d-e)^(f+g*h)-i";
    init_stack(&S,strlen(str));
    infixtopostfix(&S,str);

}