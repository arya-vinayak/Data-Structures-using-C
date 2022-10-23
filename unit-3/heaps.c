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
       
    for(i = 1;i<n;i++)
    {
        ele = a[i];
        c = i;
        p = (c-1)/2;
        while(c>0 && a[p]<ele)
        {
            a[c] = a[p];
            c = p;
            p = (c-1)/2;
        }
        a[c] = ele;
    }

    printf("The elements are\n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }


    for(i = n-1;i > 0;i--)
    {
        ele = a[i];
        a[i] = a[0];
        p = 0;
        if(i == 1)
        {
            c = -1;
        }
        else
        {
            c = 1;
        }
        if(i > 2 && a[2] > a[1])
        {
            c = 2;
        }
        while(c >= 0 && ele < a[c])
        {
            a[p] = a[c];
            p = c;
            c = 2*p + 1;
            if(c + 1 <= i-1 && a[c]<a[c+1])
            {
                c = c+1;
            }
            if(c > i-1)
            {
                c = -1;
            }
            
        }
        a[p] = ele;
    }
    
    printf("\nThe sorted elements are\n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;


}