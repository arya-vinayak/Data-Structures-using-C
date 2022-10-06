

/*
#Deletion of a node in a binary search tree

->leaf node
->node has 1 child
->node has two children
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *lchild,*rchild;
}Node;

typedef struct tree
{
    Node* root;
}Tree;

void init(Tree* pt)
{
    pt->root = NULL;
}

Node* createNode(int data)
{
    if(data != -1)
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        newnode->info = data;
        return newnode;
    }
    else
    {
        return NULL;
    }
}
Node* createTree(Node* root,int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    if(data < root->info)
    {
        root->lchild = createTree(root->lchild,data);
    }
    else if(data > root->info)
    {
        root->rchild = createTree(root->rchild,data);
    }
    else
    {
        printf("duplicate element\n");
        return NULL;
    }
    return root;
}

Node* inorderSuccessor(Node* root)
{
    if(root->lchild == NULL)
    {
        return root;
    }
    return inorderSuccessor(root->lchild);
}


Node* delete(Node* root,int ele)
{
    if(root == NULL)
    {
        printf("Element not found in the tree!\n");
        return NULL;
    }
    if(ele > root->info)
    {
        delete(root->rchild,ele);
    }
    else if(ele < root->info)
    {
        delete(root->lchild,ele);
    }
    else
    {
        Node* temp = root;
        if(root->lchild == NULL && root->rchild == NULL)
        {
            free(temp);
            temp = NULL;
            root = NULL;
        }
        else if(root->lchild == NULL)
        {
            root = root->rchild;
            free(temp);
            temp = NULL;
        }
        else if(root->rchild == NULL)
        {
            root = root->lchild;
            free(temp);
            temp = NULL;
        }
        else
        {
            root->info = (inorderSuccessor(root->rchild))->info;
            root->rchild = delete(root->rchild,root->info);
        }
        return root;
    }
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->info);
        inorder(root->rchild);
    }
    else
    {
        return;
    }
}


int main()
{
    Tree BST;
    init(&BST);
    printf("Enter the elements:\n");
    int data;
    do
    {
        scanf("%d",&data);
        if(BST.root == NULL)
        {
            BST.root = createTree(BST.root,data);
        }
        else
        {
            createTree(BST.root,data);
        }
    }while(data != -1);

    printf("\nInorder traversal of the binary search tree:\n");
    inorder(BST.root);

    printf("\nEnter the element to be deleted :\n");
    int dele;
    scanf("%d",&dele);
    delete(BST.root,dele);

    printf("\nInorder traversal of the binary search tree:\n");
    inorder(BST.root);

    return 0;

}