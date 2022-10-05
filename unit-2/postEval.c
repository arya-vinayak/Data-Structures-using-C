#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct stack
{
    int top;
    int* stackelements;
    int capacity;
};
typedef struct stack Stack;

void init(Stack* S,int size);
int isEmpty(Stack* S);
int isFull(Stack* S);
void push(Stack* S,int ele);
int pop(Stack* S);
int isOperator(char ch);
void eval(Stack* S,char* exp);
int operation(char ch,int a,int b);


void init(Stack* S,int size)
{
    S->top = -1;
    S->stackelements = (int*)malloc(sizeof(int)*size);
    S->capacity = size;
}


int isEmpty(Stack* S)
{
    return S->top == -1;
}

int isFull(Stack* S)
{
    return (S->top == (S->capacity-1));
}



void push(Stack* S,int ele)
{
    if(isFull(S))
    {
        printf("StackOverflow\n");
        return;
    }
    else
    {
        S->top++;
        S->stackelements[S->top] = ele;
    }
}

int pop(Stack* S)
{
    if(isEmpty(S))
    {
        printf("StackUnderflow\n");
        exit(0);
    }
    else
    {
        int ele = S->stackelements[S->top];
        S->top--;
        return ele;
    }
}

int operation(char ch,int a,int b)
{
    int t1;
    switch(ch)
    {
        case '+':
        t1 = a + b;
        break;

        case '-':
        t1 = a - b;
        break;

        case '/':
        t1 = a / b;
        break;

        case '*':
        t1 = a * b;
        break;

        case '^':
        t1 = pow(a,b);
        break;
    }
    return t1;
}
int isOperator(char ch)
{
    switch(ch)
    {

    
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        return 1;
        break;
        default:
        return 0; 
    }


}

void eval(Stack* S,char* exp)
{
    int len = strlen(exp);
    char ch;
    int a,b;

    for(int i = 0;i < len;i++)
    {
        ch = exp[i];
        if(!isOperator(ch))
        {
            if(!isFull(S))
            {
                push(S,atoi(&ch));
            }
            else
            {
                printf("Stack is full increase its size\n");
            }
            
        }
        else
        {
            if(S->top != -1)
            {
                a = pop(S);
                b = pop(S);
                push(S,operation(ch,b,a));
            }
            else
            {
                printf("Invalid postfix expression to evaluate\n");
            }

        }
    }
    int res = pop(S);
    printf("the result of the postfix expression is: %d",res);

}

int main()
{
    Stack S;
    int size;
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    init(&S,size);
    char postfix[size];

    printf("Enter the postfix expression\n");
    scanf("%s",postfix);

    eval(&S,postfix);
    return 0;
}





