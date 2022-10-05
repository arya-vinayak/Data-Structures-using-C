#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue
{
    int* qe;
    int qsize;
    int front;
    int rear;
};
typedef struct queue Stack;


void init_stack(Stack* S,int size);
Stack push(Stack S,int ele);
int pop(Stack S);
void peek(Stack* S);
int isEmpty(Stack* S);
int isFull(Stack* S);
void display(Stack* S);
void init_queue(Stack* Q,int size);
int dequeue(Stack* S);





void init_queue(Stack* Q,int size)
{
    Q->front = -1;
    Q->rear = -1;
    Q->qsize = size;
    Q->qe = (int*)malloc(sizeof(int)*size);
}


void init_stack(Stack* S,int size)
{
    init_queue(S,size);

}

int isFull(Stack* S)
{
    if((S->front==0 && S->rear==S->qsize-1)||(S->rear == S->front-1))
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack* S)
{
    if(S->front == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue(Stack* S,int ele)
{
    if(S->front == -1)
    {
        S->front++;
    }
    S->rear = (S->rear+1)%S->qsize;
    S->qe[S->rear] = ele;

}
Stack push(Stack S,int ele)
{
    Stack auxQ;
    init_queue(&S,S.qsize);
    if(isFull(&S))
    {
        printf("Stack Overflow...cannot push\n");
        return S;
    }
    enqueue(&auxQ,ele);
    if(isEmpty(&S))
    {
        return auxQ;
    }
    else{}
    while(!isEmpty(&S))
    {
        
        enqueue(&auxQ,dequeue(&S));
    }
    return auxQ;
}
int pop(Stack S)
{
    int ele;
    if(isEmpty(&S))
    {
        printf("STack is empty\n");
        return -1;
    }
    ele = S.qe[S.front];
    return ele;


}
int dequeue(Stack* S)
{
    int ele;
    ele = S->qe[S->front];
    if(S->front == S->rear)
    {
        S->front = -1;
        S->rear = -1;
    }
    else
    {
        S->front = (S->front+1)%S->qsize;

    }
    return ele;
}

void peek(Stack* S)
{
    int ele = -1;
    if(isEmpty(S))
    {
        printf("Stack is empty\n");
    }
    else{
        ele = S->qe[S->front];
        printf("%d\n",ele);
    }

}

void display(Stack* Q)
{
    if(isEmpty(Q))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Contents of the stack are\n");
        for(int i = Q->front;i != Q->rear;i = (i+1)%Q->qsize)
        {
            printf("%d\t",Q->qe[i]);
        }
        printf("%d\t",Q->qe[Q->rear]);
        printf("\n");
    }
}


int main()
{
    int choice,ele,size;
    Stack S;
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    init_stack(&S,size);
    while(1)
    {
        printf("\nMenu\n1)Push\n2)Pop\n3)Display\n4)Peep\n5)Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            printf("Enter the element to be pushed into the stackl\n");
            scanf("%d",&ele);
            S = push(S,ele);
            break;

            case 2 :
            ele = pop(S);
            printf("\n%d has been popped\n",&ele);
            break;
            case 3 :
            display(&S);
            break;
            case 4 :
            peek(&S);
            break;
            case 5 :
            exit(0);
            break;
          
        }

    }

}
