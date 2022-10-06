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
        newnode->info = data;
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        return newnode;
    }
    return NULL;
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

void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->info);
    }
}

int findmin(Node* root)
{
    if(root == NULL)
    {
        printf("empty BST\n");
        return -1;
    }
    Node* cur = root;
    while(cur->lchild != NULL)
    {
        cur = cur->lchild;
    }
    return cur->info;
}

int findmax(Node* root)
{
    if(root == NULL)
    {
        printf("\nEmpty BST\n");
        return -1;
    }
    Node* cur = root;
    while(cur->rchild != NULL)
    {
        cur = cur->rchild;
    }
    return cur->info;
}

int leafcount(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    else
    {
        int l,r;
        l = leafcount(root->lchild);
        r = leafcount(root->rchild);
        return l+r;
    }
}

int nonleaf(Node* root)
{
    if(root == NULL || (root->lchild == NULL && root->rchild == NULL))
    {
        return 0;
    }
    return (nonleaf(root->lchild) + 1 + nonleaf(root->rchild));
}

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int l,r;
        l = height(root->lchild);
        r = height(root->rchild);
        if(l > r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
}
void mirror(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Node* temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    mirror(root->lchild);
    mirror(root->rchild);
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
    // printf("\nPreorder traversal of the binary search tree:\n");
    // preorder(BST.root);
    // printf("\nPostorder traversal of the binary search tree:\n");
    // postorder(BST.root);
    printf("\nMin element : %d\n",findmin(BST.root));
    printf("\nMax element : %d\n",findmax(BST.root));
    printf("\nNumber of leaf nodes are : %d\n",leafcount(BST.root));
    printf("\nNumber of nonleaf nodes are : %d\n",nonleaf(BST.root));
    printf("\nHeight of tree : %d\n",height(BST.root));
    mirror(BST.root);
    printf("\nInorder traversal of the binary search tree:\n");
    inorder(BST.root);


    return 0;
}