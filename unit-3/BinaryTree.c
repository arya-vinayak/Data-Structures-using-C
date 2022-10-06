#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int info;
    struct node *lchild,*rchild;
}Node;

typedef struct bt
{
    Node* root;
}Bt;

void init(Bt* bptr)
{
    bptr->root = NULL;
}

Node* createNode(Bt* bptr)
{
    int info;
    printf("Enter the node info\n");
    scanf("%d",&info);

    if(info == -1)
    {
        return NULL;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->info = info;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if(bptr->root == NULL)
    {
        printf("Creating root Node\n");
        bptr->root = newnode;
    }

    printf("Creating left child for Node %d\n",info);
    newnode->lchild = createNode(bptr);
    
    printf("Creating right child for Node %d\n",info);
    newnode->rchild = createNode(bptr);

    return newnode;
}


void inorder(Node* root)
{
    
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->lchild);
        printf("%d ",root->info);
        inorder(root->rchild);
    }
}

int main()
{
    Bt tree;
    init(&tree);
    tree.root = createNode(&tree);
    printf("Inorder traversal\n");
    inorder(tree.root);
    return 0;
}