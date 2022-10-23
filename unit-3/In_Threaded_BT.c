#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left,*right;
    int lthread,rthread;
}Node;

Node* insert(Node* root,int x)
{
    Node *ptr,*parent;
    ptr = root;
    parent = NULL;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->lthread = 1;
    newnode->rthread = 1;

    if(root == NULL)
    {
        return newnode;
    }

    while(ptr != NULL)
    {
        if(x == ptr->info)
        {
            printf("duplicate\n");
            return root;
        }
        parent = ptr;
        if(x > ptr->info)
        {
            if(ptr->rthread == 0)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(ptr->lthread == 0)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
            
        }
    }
    if(x < parent->info)
    {
        newnode->left = parent->left;
        newnode->right = parent;
        parent->lthread = 0;
        parent->left = newnode;
    }
    else
    {
        newnode->right = parent->right;
        newnode->left = parent;
        parent->right = newnode;
        parent->rthread = 0;
    }
    return root;
}

Node* inordersuccessor(Node* ptr)
{
   if(ptr->rthread == 1)
   {
        return ptr->right;
   }
   ptr = ptr->right;
   while(ptr->lthread == 0)
   {
        ptr = ptr->left;

   }
   return ptr;

}


void inorder(Node* root)
{
    Node* ptr = root;
    if(root == NULL)
    {
        printf("Empty\n");
        return;
    }

    while(ptr->lthread == 0)
    {
        ptr = ptr->left;
    }

    while(ptr != NULL)
    {
        printf("%d ",ptr->info);
        ptr = inordersuccessor(ptr);
    }
   
}
int main(){
    Node *root = NULL;

    root = insert(root, 90);
    root = insert(root, 80);
    root = insert(root, 100);
    root = insert(root, 70);
    
    inorder(root);

    return 0;
}