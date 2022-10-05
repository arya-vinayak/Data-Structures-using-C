#include<stdio.h>
#include<stdlib.h>



struct expressiontree
{
    char op;
    struct expressiontree* lchild;
    struct expressiontree* rchild;
};
typedef struct expressiontree Etree;

struct stack
{
    Etree* ele[20];
    int top;
};
typedef struct stack Stack;

Etree* createNode(char e)
{
    Etree* newnode = (Etree*)malloc(sizeof(Etree));
    newnode->op = e;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

}
int isoperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        return 1;
        break;
        default:
        return 0;
    }

}

Etree* build_Etree(Etree* root,char postfix[])
{
    int length = strlen(postfix);
    Etree* newnode;
    Stack S;
    init_stack(&S);
    for(int i = 0;i < length;i++)
    {
        if(isoperator(postfix[i]))
        {
            Etree *rop,*lop;
            rop = pop(&S);
            lop = pop(&S);
            newnode = createNode(postfix[i]);
            newnode->lchild = lop;
            newnode->rchild = rop;

        }
        else
        {
            newnode = createNode(postfix[i]);
            push(&S,newnode);
            
            


        }
    }
}
float evaluate(Etree* root)
{
    if(isoperator(root->op))
    {
        switch(root->op)
        {
            case '+':
            evaluate(root->lchild) + evaluate(root->rchild);
            break;

            case '-':
            evaluate(root->lchild) - evaluate(root->rchild);
            break;

            case '*':
            evaluate(root->lchild) * evaluate(root->rchild);
            break;

            case '/':
            evaluate(root->lchild) / evaluate(root->rchild);
            break;
        }
    }
}


int main()
{
    char postfix[30];
    Etree* root = NULL;
    printf("\nEnter the postfix Expression: ");
    scanf("%s",postfix);

    Etree* root = build_Etree(root,postfix);
    float result = -1;
    result = evaluate(root);


}