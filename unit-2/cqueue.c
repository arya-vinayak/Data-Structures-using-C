/*
Circular Queue


*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue
{
    int front;
    int rear;
    int* qe;
    int qsize;

};
typedef struct queue Queue;


void init_queue(Queue* Q,int size)
{
    Q->front = -1;
    Q->rear = -1;
    Q->qsize = size;
    Q->qe = (int*)malloc(sizeof(int)*size);

}

int isFull(Queue* Q)
{
    if((Q->front == 0 && Q->rear == Q->qsize-1) || ( Q->rear == Q->front-1) )
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue* Q)
{
    if(Q->front == -1 )
    {
        return 1;

    }
    return 0;
}

void enqueue(Queue* Q,int ele)
{
    if(isFull(Q))
    {
        printf("Queue is Full\n");
    }
    else if(isEmpty(Q))
    {
        Q->front++;
        Q->rear++;
        Q->qe[Q->rear] = ele;

    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->qsize;
        Q->qe[Q->rear] = ele;
    }
}

int dequeue(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("\nQueue is empty,nothing can be dequequed\n");
        return -1;
    }
    else
    {
        int ele;
        ele = Q->qe[Q->front];
        if(Q->rear == 0)//imp
        {
            
            Q->rear = -1;
            Q->front = -1;
        }
        else
        {
            Q->front = (Q->front + 1)% Q->qsize;

        }
        return ele;
    }
}


void display(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("The Queue is empty\n");
    }
    else
    {
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
    Queue Q;
    printf("Enter the size of the required queue\n");
    int size;
    scanf("%d",&size);
    init_queue(&Q,size);
    int choice,ele;
    do
    {
        printf("Menu\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element\n");
            scanf("%d",&ele);
            enqueue(&Q,ele);
            break;

            case 2:
            dequeue(&Q);
            break;

            case 3:
            display(&Q);
            break;


            case 4:
            exit(0);
            break;

        }

    }
    while(choice < 5);
    return 0;


}



