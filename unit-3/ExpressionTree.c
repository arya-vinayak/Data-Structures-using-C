#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 50
typedef struct node
{
    char info;
    struct node *left,*right;
}Node;

typedef struct tree
{
    Node* root;
}Tree;

typedef struct stack
{
    Node* s[MAX];
    int top;
}Stack;

void init_tree(Tree* pt)
{
    pt->root = NULL;
}

void init_Stack(Stack* S)
{
    S->top = -1;
}

int push(Stack* S,Node* ele)
{
    if(S->top == MAX -1)
    {
        return 0;
    }
    S->top++;
    S->s[S->top] = ele;
    return 1;
}

Node* pop(Stack* S)//ASSUMPTION : empty check before performing a pop operation
{
    Node* temp = S->s[S->top];
    S->top--;
    return temp; 
}

float eval(Node* root)
{
    float res;
    switch (root->info)
    {
        case '+':
        res = eval(root->left)+eval(root->right);
        break;
        case '-':
        res = eval(root->left)-eval(root->right);
        break;
        case '*':
        res = eval(root->left)*eval(root->right);
        break;
        case '/':
        res = eval(root->left)/eval(root->right);
        break;
        default:
        return root->info - '0';//convert character to a number
    }
    return res;
    
}

float eval_tree(Tree* T)
{
    return eval(T->root);
}




int main()
{
    char postfix[MAX];
    int i  = 0;
    Stack S;
    Tree T;
    init_Stack(&S);
    init_tree(&T);
    printf("Enter the postfix expression\n ");
    scanf("%s",postfix);
    while(postfix[i] != '\0')
    {
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->info = postfix[i];
        temp->left = NULL;
        temp->right = NULL;
        if(isdigit(postfix[i]))
        {
            push(&S,temp);
        }
        else
        {
            temp->right = pop(&S);
            temp->left = pop(&S);
            push(&S,temp);
        }
        i++;
    }

    T.root = pop(&S);
    printf("On evalation of the expression we get:\n");
    printf("%f",eval_tree(&T));


}