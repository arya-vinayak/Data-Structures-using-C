/* 
 +,-,*,/ :- left associative 
 ^ right associativity
 + - ;- 
  a + b * c/d = abc*d/+

  a * (b + c) = abc+*


  a + b * c - d/e * f
  token    stack     postfix
    a                   a
    +        +          a
    b        +          ab
    *        +*         ab
    c        +*         abc
    -        -          abc*+ ( * gets added to the postfix expression because it is of higher precedence
                                and)



conditions to be checked in the program

1)if token is an operand copy it to the postfix expression
2)if the token is an operator
  ->if the stcak is empty,push it to the stack
  ->incoming op precedence > precedence of the element at the top of the stack
     - we push the operator into the stack
  ->incoming operator precedence < precedence of the element at the top of the stack
     - we add it to the postfix expression
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int top,capacity;
    char *arr;
}Stack;

void createStack(Stack *sptr,int capacity)
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

void infixToPostfix(char *expression)
{
    Stack s;
    createStack(&s,strlen(expression));
    char postfix[strlen(expression)];
    int k = 0;
    for(int i = 0;i < strlen(expression);i++)
    {
        if(isOperand(expression[i]))
        {
            postfix[k++] = expression[i];
        }
        else if(expression[i] == '(')
        {
            push(&s,expression[i]);
        }
        else if(expression[i] == ')')
        {
            while(!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[k++] = pop(&s);
            }
            if(isEmpty(&s))
            {
                printf("Invalid infix expression\n");
                exit(0);
            }
            pop(&s);
        }
        else
        {
            if(prec(expression[i]) > prec(peek(&s)) || peek(&s)=='(')
            {
                push(&s,expression[i]);
            }
            else
            {
                while(!isEmpty(&s) && prec(expression[i]) <= prec(peek(&s)))
                {
                    if(expression[i] == '^')
                    {
                        push(&s,expression[i]);
                        break;

                    }
                    else
                    {
                        postfix[k++] = pop(&s);
                    }
                    
                }
                if(expression[i] != '^')
                {
                    push(&s,expression[i]);

                }
                
            }
        }


    }
    while(!isEmpty(&s))
    {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
    printf("the postfix expression:\n");
    printf("%s",postfix);


}

int main() {
    char exp[20];
    printf("Enter infix Expression: ");
    scanf("%s",exp);
    infixToPostfix(exp);
    return 0;
}
