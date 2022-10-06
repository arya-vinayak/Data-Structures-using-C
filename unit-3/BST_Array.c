#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    int used;
}Node;

void init(Node bst[50])
{
   for(int i = 0;i < 50;i++)
   {
        bst[i].used = 0;
   }
}
void create(Node bst[50])
{
    printf("\nEnter the root node info\n");
    scanf("%d",&bst[0].info);
    bst[0].used = 1;
    int temp,choice;
    
    do
    {
        printf("Enter the element:\n");
        scanf("%d",&temp);
        int i = 0;
        while(i < 50 && bst[i].used)
        {
            if(temp > bst[i].info)
            {
                i = 2*i + 2;
            }
            else
            {
                i = 2*i + 1; 
            }
        }
        if(i >= 50)
        {
            printf("You cannot insert  a node any further!\n");
            exit(0);
        }
        else
        {
            bst[i].info = temp;
            bst[i].used = 1;
        }
        printf("\nDo you want to insert a node ? ");
        scanf("%d",&choice);
    }while(choice != 0);
}

void inorder(Node bst[50],int p)
{
    if(bst[p].used)
    {
        inorder(bst,2*p + 1);
        printf("%d ",bst[p].info);
        inorder(bst,2*p + 2);
    }
    else
    {
        return;
    }
}
int main()
{
    Node bst[50];
    init(bst);
    create(bst);
    inorder(bst,0);
}