/*
Circular Queue
*/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int no;
    struct node* link;
};

typedef struct node Node;

struct queue
{
    Node* front;
    Node* rear;
};
typedef struct queue Queue;


void init(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(Queue* Q)
{
    if(!Q->front && !Q->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue* Q,int ele)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->link = NULL;
    newnode->no = ele;
    if(isEmpty(Q))
    {
        Q->front = newnode;
        Q->rear = newnode;
        Q->rear->link = Q->front;
        return;
    }
    else
    {
        newnode->link = Q->front;
        Q->rear->link = newnode;
        Q->rear = newnode;
    }
}

int dequeue(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        Node* temp = Q->front;
        int ele = temp->no;
        Node* lastnode = Q->rear;
        if(Q->front == Q->rear)
        {
            Q->front = NULL;
            Q->rear = NULL;
        }
        else
        {
            Q->front = Q->front->link;
            lastnode->link = Q->front;
        }
        free(temp);
        temp = NULL;
        return ele;

    }
}
void display(Queue* Q)
{
    Node* cur;
    cur = Q->front;
    if(isEmpty(Q))
    {
        printf("Empty Queue\n");
        return;
    }
    while(cur->link != Q->front)
    {
        printf("%d\t",cur->no);
        cur = cur->link;
    }
    printf("%d\t",cur->no);

}

int survivor(int n,int k)
{
    Queue Q;
    init(&Q);

    for(int i = 1; i <= n;i++)
    {
        enqueue(&Q,i);
    }

    if(n == 1)
    {
        return dequeue(&Q);
    }
    else if(k > n)
    {
        return -1;
    }
    else
    {
        while(Q.front != Q.rear)
        {
            for(int i = 0;i < k;i++)
            {
                enqueue(&Q,dequeue(&Q));
            }
            printf("Soldier %d has been killed\n",dequeue(&Q));

        }
        return dequeue(&Q);
    }

}
int main()
{
    return 0;
    printf("Enter the value of n and k\n");
    int n,k;
    scanf("%d%d",&n,&k);
    int saved = survivor(n,k);
    printf("soldier %d is the survivor\n",saved);
    return 0;
    
    
}