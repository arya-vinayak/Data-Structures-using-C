#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
    int top,capacity;
    char *arr;
}Stack;

void init(Stack *sptr,int capacity)
{
    sptr->capacity = capacity;
    sptr->top = -1;
    sptr->arr = (char *) malloc(capacity * sizeof(char));
}

int isFull(Stack *sptr)
{
    return sptr->top == sptr->capacity - 1;
}

int isEmpty(Stack *sptr)
{
    return sptr->top == -1;
}

void push(Stack *sptr,char ele)
{
    if(isFull(sptr))
    {
        printf("Stack Overflowed!\n");
        exit(-1);
    }
    else
    {
        sptr->arr[++(sptr->top)] = ele;
    }
}

char pop(Stack *sptr)
{
    if(isEmpty(sptr))
    {
        printf("Stack Underflowed!\n");
        return '\0';
    }
    else
    {
        return sptr->arr[sptr->top--];
    }
}

char peek(Stack *sptr)
{
    if(isEmpty(sptr))
    {
        return '\0';
    }
    else
    {
        return sptr->arr[sptr->top];
    }
}

int isOperand(char ch)
{
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    return 0;
}

int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
    }

}


void convert(Stack* S,char* exp)
{
    int len = strlen(exp);
    int k = 0;
    char postfix[len];

    for(int i = 0;i < len;i++)
    {
        if(isOperand(exp[i]))
        {
            postfix[k++] = exp[i];
        }
        else if(exp[i] == ')')
        {
            push(S,exp[i]);
        }
        else if(exp[i] == '(')
        {
            while(!isEmpty(S) && peek(S) != ')')
            {
                postfix[k++] = pop(S);
            }
            if(isEmpty(S))
            {
                printf("Invalid prefix expression\n");
            }
            pop(S);
        }
        else
        {
            if(prec(exp[i]) >= prec(peek(S)) || peek(S) == '(')
            {
                if(exp[i] == '^')
                {
                    postfix[k++] = pop(S);
                }
                else
                {
                  push(S,exp[i]);
                }
            }
            else
            {
                while(!isEmpty(S) && prec(exp[i]) < prec(peek(S)))
                {
                   
                    postfix[k++] = pop(S);
                }
                
                push(S,exp[i]);
                

            }

        }
    }
    while(!isEmpty(S))
    {
        postfix[k++] = pop(S);
    }
    postfix[k] = '\0';
    char prefix[len];
    int j = 0;
    for(int i = len-1;i >= 0;i--)
    {
        prefix[j] = postfix[i];
        j++;
    }
    prefix[j] = '\0';
    printf("The prefix expression is: %s\n",prefix);
}

int main()
{
    char exp[20];
    printf("Enter infix Expression: ");
    scanf("%s",exp);
    int len = strlen(exp);
    Stack S;
    init(&S,len);
    char rinfix[len];
    int k = 0;
    for(int i = len-1;i >= 0;i--)
    {
        rinfix[k] = exp[i];
        k++;
    }
    rinfix[k] = '\0';
   
    
    convert(&S,rinfix);
    return 0;
}