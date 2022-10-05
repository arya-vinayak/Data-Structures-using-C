/*
front of the queue - it will tell the next element to be dequeued
rear - it will the next available free slot
enqueue - it will insert the element at the rear of the queue
dequeue - it will remove an element that is present at the front of the queue
diplay the current queue
check if it is full - if rear equates to capacity -1
check if it is empty - front and rear point to -1
delete front
insert rear

the different types of queues
-linear queue
-circular queue
-double ended queue
-priority queue
*/
#include <stdio.h>
#include <stdlib.h>



typedef struct queue {
    int *qe;
    int qsize;
    int front,rear;
}Queue;

void init(Queue *qu,int size)
{
    qu->qsize = size;
    qu->front = -1;
    qu->rear = -1;
    qu->qe = (int *) malloc(size * sizeof(int));
}

int isFull(Queue *Q)
{
    return Q->rear == Q->qsize - 1;
}

int isEmpty(Queue *Q)
{
    return (Q->rear == Q->front )&&(Q->rear == -1);
}

void enqueue(Queue *Q,int ele)
{
    if(isFull(Q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if(isEmpty(Q))
            Q->front++;
        Q->rear++;
        Q->qe[Q->rear] = ele; 
    }   
}

int dequeue(Queue *Q)
{
    int ele = -1;
    if(isEmpty(Q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ele = Q->qe[Q->front];
        if(Q->front == Q->rear)
        {
            Q->front = -1;
            Q->rear = -1;
        }
        else
        {
            Q->front++;
        }
    }
    return ele;
}

void display(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is Empty!\n");
    }
    else{
        printf("Elements of queue are:\n");
        for (int i = Q->front; i <= Q->rear; i++)
        {
            printf("\t| %d |\n",Q->qe[i]);
        } 
    }
}

int main()
{
    Queue Q;
    int size;
    printf("Enter queue size: ");
    scanf("%d",&size);
    init(&Q,size);
    int choice,ele;
    do
    {
        printf("Menu:\n1.) Enqueue\n2.) Dequeue\n3.) Display queue\n4.) Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&ele);
            enqueue(&Q,ele);
            break;
        
        case 2:
            ele = dequeue(&Q);
            if (ele != -1)
                printf("Dequeued element %d\n",ele);
            break;

        case 3:
            display(&Q);
            break;        
            
        default:
            exit(0);
        }
    } while (choice < 5);
    return 0;
}