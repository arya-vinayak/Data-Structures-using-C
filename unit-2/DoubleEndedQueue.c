#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int info;
    struct node* link;
};
typedef struct node Node;

struct queue
{
    Node* front;
    Node* rear;
};
typedef struct queue Queue;

void init(Queue* Q);
int isEmpty(Queue* Q);
void insertFront(Queue* Q,int ele);
void insertRear(Queue* Q,int ele);
int deleteFront(Queue* Q);
int deleteRear(Queue* Q);
int peekFront(Queue* Q);
int peekRear(Queue* Q);
void display(Queue* Q);


void init(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}
int isEmpty(Queue* Q)
{
    if(Q->front == NULL && Q->rear == NULL)
    {
        return 1;

    }
    return 0;
}

void insertFront(Queue* Q,int ele)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = ele;
    temp->link = NULL;
    if(isEmpty(Q))
    {
        Q->rear = Q->front = temp;

    }
    else
    {
        temp->link = Q->front;
        Q->front = temp;
    }
}


void insertRear(Queue* Q,int ele)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = ele;
    temp->link = NULL;
    if(isEmpty(Q))
    {
        Q->front = Q->rear = temp;
    }
    else
    {
        Q->rear->link = temp;   
        Q->rear = temp;
    }
}


int deleteFront(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else 
    {
        Node* temp = Q->front;
        int ele = temp->info;
        if(Q->front == Q->rear)
        {
            Q->front = Q->rear = NULL;

        }
        else
        {
            
            Q->front = Q->front->link;
        }
        free(temp);
        return ele;
    }
}

int deleteRear(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else 
    {
        Node* temp = Q->rear;
        int ele = temp->info;
        if(Q->front == Q->rear)
        {
            Q->front = Q->rear = NULL;

        }
        else
        {
            Node* prev = Q->front;
            while(prev->link != Q->rear)
            {
                prev = prev->link;
            }
            Q->rear = prev;
        }
        free(temp);
        return ele;
    }
    
}

int peekFront(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Q->front->info;
}
int peekRear(Queue* Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Q->rear->info;
}

void display(Queue* Q)
{
    
    if(isEmpty(Q))
    {
        printf("Queue is empty\n");
    }
    else if(Q->front == Q->rear)
    {
        printf("Elements of the Queue are:\n");
        printf("\n%d\n",Q->front->info);
    }
    else
    {
        Node* temp = Q->front;
        printf("Elements of the Queue are:\n");
        while(temp != Q->rear)
        {
            printf("%d\t",temp->info);
            temp = temp->link;
        }
        printf("%d\n",temp->info);
    }
}

int main()
{
    Queue Q;
    init(&Q);
    int choice,ele;
    do
    {
        printf("Menu:\n1) Insert Front\t2) Insert Rear\n3) Remove Front\t4) Remove Rear\n5) Peak Front\t6) Peak Rear\n7) Display\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d",&ele);
            insertFront(&Q,ele);
            break;
        
        case 2:
            printf("Enter element to insert: ");
            scanf("%d",&ele);
            insertRear(&Q,ele);
            break;

        case 3:
            ele = deleteFront(&Q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Deleted node with info %d\n",ele);
            }
            break;

        case 4:
            ele = deleteRear(&Q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Deleted node with info %d\n",ele);
            }
            break;
        
        case 5:
            ele = peekFront(&Q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Peeked at %d!\n",ele);
            }    
            break;

        case 6:
            ele = peekRear(&Q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Peeked at %d!\n",ele);
            }    
            break;

        case 7:
            display(&Q);
            break;

        default:
            exit(0);
        }
    } while (choice < 9);
    
}


