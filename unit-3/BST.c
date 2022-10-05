#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node Node;
struct bst
{
    Node* troot;
};

typedef struct bst BST;

void init(BST* bstree)
{
    bstree->troot = NULL;
}


Node* createnode(int data)
{
    Node* newnode;
    newnode= (Node*)malloc(sizeof(Node));
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->key = data;
}
Node* insert(Node* root,int data)
{
    if(root == NULL)
    {
        root = createnode(data);
        return root;
    }
    if(data < root->key)
    {
        root->lchild = insert(root->lchild,data);
    }
    else if(data > root->key)
    {
        root->rchild = insert(root->rchild,data);
    }
    else
    {
        printf("\n Node data is duplicate\n");
    }
    return root;
}

void preorder(Node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->key);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->key);
        inorder(root->rchild);
        
    }
}

int findmin(Node* root)
{
    Node* cur = root;
    if(root == NULL)
    {
        printf("\n Empty BST \n");
        return -1;
    }
    while(cur->lchild != NULL)
    {
        cur = cur->lchild;
    }
    return cur->key;


}
int findmax(Node* root)
{
    Node* cur = root;
    if(root == NULL)
    {
        printf("\n Empty BST \n");
        return -1;
    }
    while(cur->rchild != NULL)
    {
        cur = cur->rchild;
    }
    return cur->key;
}

int leafcount(Node* troot)
{
    int l,r;
    if(troot != NULL)
    {
        l = leafcount(troot->lchild);
        r = leafcount(troot->rchild);
        return (l+r);
    }
    
    
}

int nonleafcount(Node* troot)
{
    if(troot == NULL || (troot->lchild == NULL && troot->rchild == NULL))
    {
        return 0;
    }
    return(nonleafcount(troot->lchild) + 1 + nonleafcount(troot->rchild));
}

int height(Node* troot)
{
    int l,r;
    if(troot != NULL)

    {
        if(troot->lchild == NULL && troot->rchild == NULL)
        {
            return 0;
        }
        l = height(troot->lchild);
        r = height(troot->rchild);
        if(l>r)
        {
            return l+1;
        }
        return r+1;
    }
    return -1;
}

int size(Node* troot)
{
    if(troot == NULL)
    {
        return 0;
    }
    return (size(troot->lchild) + 1 + size(troot->rchild));
}

void mirror(Node* troot)
{
    Node* temp = NULL;
    if(troot == NULL)
    {
        return;
    }
    temp = troot->lchild;
    troot->lchild = troot->rchild;
    troot->rchild = temp;
    mirror(troot->lchild);
    mirror(troot->rchild);
}
Node* deleteNode(Node* troot,int ele)
{
    Node* temp = NULL;
    if(troot == NULL)
    {
        return NULL;
    }
    if(ele < troot->key)
    {
        troot->lchild = deleteNode(troot->lchild,ele);
    }
    else if(ele > troot->key)
    {
        troot->rchild = deleteNode(troot->rchild,ele);
    }
    else
    {
        if(troot->lchild == NULL )
        {
            temp = troot->rchild;
            free(troot);
            return temp;
        }
        else if(troot->rchild == NULL)
        {
            temp = troot->rchild;
            free(troot);
            return temp;
        }
        else
        {
            troot->key = findmin(troot->rchild);
            troot->rchild = deleteNode(troot->rchild,troot->key);
            
        }

    }
}
int main()
{
    int data;
    BST bstree;
    init(&bstree);
    int flag = 1;
    while(flag)
    {
        printf("\nEnter the node key value -1 to stop : ");
        scanf("%d",&data);
        if(data == -1)
        {
            flag = 0;
        }
        else
        {
            if(bstree.troot == NULL)
            {
                bstree.troot = insert(bstree.troot,data);
            }
            else
            {
                insert(bstree.troot,data);
            }
        }
    }

    printf("\nPreorder Traversal \n");
    preorder(bstree.troot);

    printf("\nInorder Traversal \n");
    inorder(bstree.troot);

    int min = findmin(bstree.troot);
    int max = findmax(bstree.troot);

    printf("\n Min value in BST : %d",min);
    printf("\n Min value in BST : %d",max);
    int leaf = leafcount(bstree.troot);
    printf("\nNo of leaves are : %d\n",leaf);
    int nleaf = nonleafcount(bstree.troot);
    printf("\nNo of nonleaves are : %d\n",nleaf);

    int ht = height(bstree.troot);
    printf("\n height of the tree is : %d\n",ht);


    int nodecount = size(bstree.troot);
    printf("\nthe number of nodes are: %d\n",nodecount);

    // mirror(bstree.troot);
    // printf("\nInorder Traversal \n");
    // inorder(bstree.troot);

    int ele;

    printf("enter the element to be deleted:\n");
    scanf("%d",&ele);

    bstree.troot = deleteNode(bstree.troot,ele);

    printf("\nInorder Traversal \n");
    inorder(bstree.troot);



    return 0;


}