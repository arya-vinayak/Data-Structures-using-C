
#include<stdio.h>
#include<stdlib.h>
/*
int fact(int n)
{
    if(n == 1)
    {
        return n;

    }
    return n*fact(n-1);
}
*/

//Tail recursive function - deletes the stack frame consecutively as the next recursive call takes place,hence efficient memory use 

int fact(int n,int a)
{
    if(n == 1)
    {
        return a;
    }
    return fact(n-1,n*a);
}
