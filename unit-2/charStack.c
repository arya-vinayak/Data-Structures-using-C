#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100


struct stack
{
    int top;
    int capacity;
    char* stackelements;
};
typedef struct stack Stack;

void init_stack(Stack* S,int size)
{
    S->top = -1;
    S->capacity = size;
    S->stackelements = (char*)malloc(size*sizeof(char));    
}

int isFull(Stack* S)
{
    return S->top == S->capacity-1;
}

int isEmpty(Stack* S)
{
    return S->top == -1;
}

void push(Stack* S,char ele)
{
    if(isFull(S))
    {
        printf("StackOverflow\n");
    }
    else
    {
        S->top++;
        S->stackelements[S->top]  = ele;
    }
}

char pop(Stack* S)
{
    if(isEmpty(S))
    {
        printf("Stack Underflow\n");
        return '!';
    }
    else
    {
        char ch = S->stackelements[S->top];
        S->top--;
        return ch;
        
    }
}
char peep(Stack* S)
{
    return S->stackelements[S->top];
}

void display(Stack* S)
{
    if(isEmpty(S))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements of the stack are\n");
        for(int i = S->top;i >= 0 ;i--)
        {
            printf("%c\t",S->stackelements[i]);
        }
        printf("\n");

    }
}
void convert(Stack* S,char* infix)
{
    int len = strlen(infix);
    char postfix[len];
    int k = 0;
    int i = 0;
    char ch;
    

    while((ch = infix[i]) != '\0')
    {

    }

}

int main()
{
    Stack S;
    init_stack(&S,SIZE);
    char infix[SIZE];
    printf("Enter the infix expression\n");
    scanf(" %s",infix);
    convert(&S,infix);


    return 0;
    
          
        

    
}
