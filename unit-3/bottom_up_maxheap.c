#include<stdio.h>
#include<stdlib.h>
//max heap

#define MAX 50

int main()
{
    int a[MAX];
    int i,c,p,n,ele;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }


    for(i = (n/2)-1;i >= 0;i--)
    {
       
        p = i;
        c = 2*p + 1;
        while(c < n)
        {
            if(c+1 < n)
            {
                if(a[c] < a[c+1])
                {
                    c = c+1;
                }
            }
            if(ele < a[c])
            {
                a[p] = a[c];
                p = c;
                c= 2*p + 1;
            }
            else
            {
                break;
            }
        }
        a[c] = ele;
        
    }
    printf("The elements are\n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }



    
    return 0;


}

