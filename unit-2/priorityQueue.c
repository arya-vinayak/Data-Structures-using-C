#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>




typedef struct node
{
    int info;
    int priority;
}Node;

struct queue
{
    int front;
    int rear;
    Node* qe;
    int qsize;
};
typedef struct queue Queue;





void init(Queue *Q,int size)
{
    Q->qsize = size;
    Q->front = -1;
    Q->rear = -1;
    Q->qe = (Node *) malloc(size * sizeof(Node));
}

int isFull(Queue *Q)
{
    return Q->rear == Q->qsize - 1;
}

int isEmpty(Queue *Q)
{
    return (Q->rear == Q->front )&&(Q->rear == -1);
}

int peek(Queue* Q,int prio)
{
    int pos;
    pos = Q->front;
    while((prio > (Q->qe[pos].priority ))&& pos <= Q->rear)
    {
        pos++;
    }
    return pos;

}

void enqueue(Queue *Q,int info,int prio)
{
    Node ele;
    ele.info = info;
    ele.priority = prio;
    if(isFull(Q))
    {
        printf("Queue is Full\n");
        return;
    }
    else if(Q->front == -1)
    {
        Q->front++;
        Q->rear++;
        Q->qe[Q->rear] = ele;
        return;
    }
    else
    {
       int pos = peek(Q,prio);
       for(int i = Q->rear;i >= pos;i--)
       {
        Q->qe[i + 1] = Q->qe[i];
       }
       Q->qe[pos] = ele;
       Q->rear++;
    }
    
}

Node dequeue(Queue *Q)
{
    Node ele;
    ele.info = -1;
    ele.priority = -1;

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
        return;
    }
    else{
        printf("Elements of queue are:\n");
        printf("Data : ");
        for(int i = Q->front; i <= Q->rear; i++)
        {
            printf("%d\t",Q->qe[i].info);
        } 
        printf("Priority : ");
        for(int i = Q->front; i <= Q->rear; i++)
        {
            printf("%d\t",Q->qe[i].priority);
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
    int choice,ele,prio;
    Node ele1;
    do
    {
        printf("Menu:\n1.) Enqueue\n2.) Dequeue\n3.) Display queue\n4.) Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element and priority\n");
            scanf("%d%d",&ele,&prio);
            enqueue(&Q,ele,prio);
            break;
        
        case 2:
            ele1 = dequeue(&Q);
            if (ele1.priority != -1)
                printf("Dequeued element %d\n",ele1.info);
            break;

        case 3:
            display(&Q);
            break;    
        case 4:
            exit(0);
            break;    
            
        default:
            exit(0);
        }
    } while (choice < 5);
    return 0;
}