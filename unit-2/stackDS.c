/*
Stack data structure
- LAST IN FIRST OUT
delete operation - pop
insert operation - push




*/

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int* stackelements;
    int capacity;
};
typedef struct stack Stack;

void init_Stack(Stack* s,int size);
void push(Stack* s,int ele);
void pop(Stack* s);
void peep(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void display(Stack* s);

void init_Stack(Stack* s,int size)
{
    s->top = -1;
    s->capacity = size;
    s->stackelements = (int*)malloc(sizeof(int)*size);
}
int isEmpty(Stack* s)
{
    return (s->top == -1);

}
int isFull(Stack* s)
{
    return (s->top == (s->capacity)-1);
}

void push(Stack* s,int ele)
{
    if(isFull(s))
    {
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->stackelements[s->top] = ele;
    }

}

void pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else{
        printf("%d has been popped\n",s->stackelements[s->top]);
        s->top--; 
    }
}

void peep(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n",s->stackelements[s->top]);
    }
}
void display(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else{
        for(int i = s->top;i >= 0;i--)
        {
            printf("%d\t",s->stackelements[i]);
        }
        printf("\n");
    }

}


int main()
{

    int stacksize,choice;
    Stack s;
    printf("\nEnter the stack size\n");
    scanf("%d",&stacksize);
    init_Stack(&s,stacksize);
    int ele;
    printf("\n Menu \n");
    while(1)
    {
        printf("\n1)Push\n2)Pop\n3)Display\n4)Peep\n5)Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            printf("Enter the element to be pushed into the stackl\n");
            scanf("%d",&ele);
            push(&s,ele);
            break;

            case 2 :
            pop(&s);
            break;
            case 3 :
            display(&s);
            break;
            case 4 :
            peep(&s);
            break;
            case 5 :
            exit(0);
            break;
          
        }

    }
    return 0;
}


