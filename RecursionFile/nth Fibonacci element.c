#include<stdio.h>

int fibonacci(int num)
{
    if(num==0)
    {
        return 0;
    }
    if(num==1)
    {
        return 1;
    }
    else{
        return (fibonacci(num-1)+fibonacci(num-2));
    }
}

void main()
{
    int n;
    printf("Enter the position of element to be found in fibonacci series:");
    scanf("%d",&n);
    printf("nth Fibonacci element is %d",fibonacci(n-1));

}

