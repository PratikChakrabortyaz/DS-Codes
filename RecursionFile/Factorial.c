#include<stdio.h>
int fact(int num)

{
    int fac;
    if(num==0)
    {
        return 1;
    }
    else{
        fac=num*fact(num-1);
        return fac;
    }

}

void main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("%d",fact(n));


}

