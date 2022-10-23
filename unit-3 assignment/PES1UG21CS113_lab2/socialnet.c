#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    

    if(users == NULL)
    {
        return NULL;
    }

    if(key == users->id)
    {
        return users;
        
    }
    else if(key < users->id)
    {
        return search(key,users->left);
    }
    else
    {
        return search(key,users->right);
    }    
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    
    if(users == NULL)
    {
        user->numfren=0;
        user->friends[0] = -1;
        return user;
    }
    if(user == NULL)
    {
        return NULL;
    }
    else
    {
        node* temp = search(user->id,users);
        while(temp != NULL)
        {
            user->id++;
            temp = search(user->id,users);
        }
    }

    if(user->numfren == 0)
    {
        user->friends[0] = -1;
    }
    else
    {
        for(int i = 0;i  < user->numfren;i++)
        {
            node* temp1 = search(user->friends[i],users);
            if(temp1 != NULL && temp1->numfren < MAX)
            {
                temp1->numfren++;
                temp1->friends[temp1->numfren-1] = user->id;
            }
            else
            {
                for(int k = i;k < user->numfren-1;k++)
                {
                    user->friends[k] = user->friends[k+1];
                }
                user->numfren--;
                i--;

            }

        }
        if(user->numfren == 0)
        {
            user->friends[0] = -1;
        }
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
    if(root == NULL)
    {
        root = user;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        if(id < root->id)
        {
            root->left = insertUser(root->left,id,user);
        }
        else if(id > root->id)
        {
            root->right = insertUser(root->right,id,user);
        }
        return root;
    }   
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE
   if(users == NULL)
   {
    return;
   }

   struct node* temp = search(id,users);

   if(temp != NULL)
   {
    if(temp->numfren != 0)
        {
            for(int i = 0;i < temp->numfren;i++)
            {
                printf("%d\n",temp->friends[i]);
            }
            
        }
        else
        {
            printf("%d\n",temp->friends[0]);
        }
   }
   else
   {
    return;
   }  
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
  //CODE HERE
  if(node->left == NULL)
  {
    return node;
  }
  return minValueNode(node->left);
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
    struct node* keynode;
    keynode = search(key, users);
    int pos;

    if(users == NULL)
    {
        return NULL;
    }

    if(keynode == NULL)
    {
        return users;
    }
    else
    {
       for(int i = 0;i < keynode->numfren;i++)
            {
                node* temp = search(keynode->friends[i],users);
                if(temp != NULL)
                {
                    pos = -1;
                    for(int j = 0;j < temp->numfren;j++)
                    {
                        if(temp->friends[j] == key)
                        {
                            pos = j;
                        }
                    }
                    if(pos != -1)
                    {
                        for(int k = pos;k < temp->numfren-1;k++)
                        {
                            temp->friends[k] = temp->friends[k+1];

                        }
                        temp->numfren--;
                        i--;    
                        
                    
                        if(temp->numfren == 0)
                        {   
                            temp->friends[0] = -1;
                        }   
                    }   
                }

            }
            return users;
    }
    
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //CODE HERE
  
  if(root == NULL)
  {
    return NULL;
  }

  if(key < root->id)
  {
     root->left = deleteNode(root->left,key);
  }
  else if(key > root->id)
  {
    root->right = deleteNode(root->right,key);
  }
  else
  {
    node* temp = root;
    if(root->left == NULL && root->right == NULL)
    {
        free(temp);
        temp = NULL;
        root = NULL;
        
    }
    else if(root->left == NULL)
    {
        root = root->right;
        free(temp);
        temp = NULL;
        
    }
    else if(root->right == NULL)
    {
        root = root->left;
        free(temp);
        temp = NULL;
        
    }
    else
    {
        root->id = (minValueNode(root->right))->id;
        root->friends = (minValueNode(root->right))->friends;
        root->numfren = (minValueNode(root->right))->numfren;
        strcpy(root->name,(minValueNode(root->right))->name);
        root->right = deleteNode(root->right,root->id);
        return root;
        
        
    } 
    
  }
  return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if(myusers != NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n",myusers->id,myusers->name);
        printInOrder(myusers->right);
    }
    else{
        return;
    }
}

int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }
    }
    return 0;
}