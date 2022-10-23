//Right Threaded binary tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int info;
    struct node *left,*right;
    int rthread;
}Node;


typedef struct tree
{
    Node* root;
}Tree;

void init(Tree* T)
{
    T->root = NULL;
}

Node* makeNode()
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    int info;
    printf("Enter the info\n");
    scanf("%d",&info);
    newnode->info = info;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->rthread = 1;//since node being inserted is by default a child node
    return newnode;


}

void setleft(Node* p,Node* temp)
{
    if(p == NULL)
    {
        return;
    }
    if(p->left != NULL)
    {
        return;
    }
    p->left = temp;
    temp->right = p;//p is the inorder successor of temp
}

void setright(Node* p,Node* temp)
{
    if(p==NULL)
    {
        return;
    }
    if(!(p->rthread))
    {
        return;
    }
    temp->right = p->right;
    p->right = temp;
    p->rthread = 0;
}


void create(Tree* T)
{
    Node *temp,*p,*q;
    int wish;
    T->root = makeNode();
    do
    {
        temp = makeNode();
        q = NULL;
        p = T->root;
        while(p != NULL)
        {
            q = p;
            if(temp->info < p->info)
            { 
                p = p->left;
            }
            else
            {
                if(p->rthread)
                {
                    break;
                }
                p = p->right;
            }

        }
        if(p == NULL)//when we were trying to add left and we reached null
        {
            setleft(q,temp);
        }
        else//when we were trying to add at the right and we reached a leaf node
        {
            setright(p,temp);
        }
        printf("Do you want to add another 1/0\n");
        scanf("%d",&wish);

    }while(wish);
}

void inorder(Tree* T)
{
    Node* p,*q;
    p = T->root;
    do
    {
        q = NULL;
        
        while(p != NULL)
        {
            q = p;
            p = p->left;
        }
        if( q != NULL)//reached left most and printing consequently
        {
            printf("%d ",q->info);
            p = p->right;
        }

        while(q->rthread && p != NULL)//checking for right threads and printing
        {
            printf("%d ",p->info);
            q = p;
            p = p->right;
        }

        
    }while(q != NULL);
    
}

int main()
{
    Tree T;
    init(&T);
    create(&T);
    inorder(&T);
    return 0;
}