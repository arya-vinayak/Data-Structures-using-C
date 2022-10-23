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


    //heapify
       
    // for(i = 1;i < n;i++)
    // {
    //     ele = a[i];
    //     c = i;
    //     p = (c-1)/2;
    //     while(c > 0 && ele > a[p]) //max heap - top down
    //     {
    //         a[c] = a[p];
    //         c = p;
    //         p = (c-1)/2;
    //     }
    //     a[c] = ele;
    // }

    // for(i = 1;i < n;i++)
    // {
    //     ele = a[i];
    //     c = i;
    //     p = (c-1)/2;
    //     while(c > 0 && ele < a[p]) //min heap - top down
    //     {
    //         a[c] = a[p];
    //         c = p;
    //         p = (c-1)/2;
    //     }
    //     a[c] = ele;
    // }

    for(int i  = (n/2)-1;i >= 0;i--)
    {
       
        p = i;
        c = 2*p + 1;
        ele = a[p];
        while( c < n)
        {
            if(c + 1 < n)
            {
                if(a[c] > a[c+1])
                {
                    c = c +1;
                }
            }
            if(ele > a[c])
            {
                a[p] = a[c];
                p = c;
                c = 2*p + 1;
            }
            else{
                break;
            }
        }
        a[p] = ele;

        
    }

    printf("The elements are\n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }


    
    return 0;


}