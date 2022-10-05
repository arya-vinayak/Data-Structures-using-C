

#include<stdio.h>
#include<stdlib.h>


struct qnode
{
    int info;
    struct qnode* next;

};
typedef struct qnode Qnode;

struct queue
{
    Qnode* front;
    Qnode* rear;
};
typedef struct queue Queue;



void init_queue(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(Queue* ptr)
{
    if((!ptr->front)&&(!ptr->rear))
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue* Q,int ele)
{
    Qnode* newnode;
    newnode = (Qnode*)malloc(sizeof(Qnode));
    newnode->info = ele;
    newnode->next = NULL;
    if(isEmpty(Q))
    {
        Q->front = newnode;
        Q->rear = newnode;
        newnode->next = Q->front;
    }
    else
    {
        newnode->next = Q->front;
        Q->rear->next = newnode;
        Q->rear = newnode;
    }
}

int dequeue(Queue* Q)
{
    int ele;
    Qnode *temp =NULL,*lastnode = NULL;
    if(isEmpty(Q))
    {
        printf("\nQueue is empty...cannot dequeue\n");
        return -1;
    }
    temp = Q->front;
    lastnode = Q->rear;
    if(Q->front == Q->rear)
    {
        ele = temp->info;
        Q->front = NULL;
        Q->rear = NULL;
        return ele;
    }
    Q->front =  Q->front->next;
    lastnode->next = Q->front;
    ele = temp->info;
    free(temp);
    return ele;
}

void display(Queue* Q)
{
    Qnode* cur;
    cur = Q->front;
    if(isEmpty(Q))
    {
        printf("Empty Queue\n");
        return;
    }
    while(cur->next != Q->front)
    {
        printf("%d\t",cur->info);
        cur = cur->next;
    }
    printf("%d\t",cur->info);

}


int main()
{
    Queue Q;
    int choice;
    init_queue(&Q);
    int ele;
    do
    {
        printf("Menu\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to be enqueued\n");
            scanf("%d",&ele);
            enqueue(&Q,ele);
            break;

            case 2:
            ele = dequeue(&Q);
            printf("%d has been dequeued\n",ele);
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
       
    } 
    while(choice < 5);
    return 0;
    
}



