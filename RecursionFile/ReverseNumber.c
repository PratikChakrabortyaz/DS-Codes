#include<stdio.h>

int reverseNumber(int num)
{
    static int rev=0;int rem;
    if(num==0)
        return rev;
    rem=num%10;
    rev=rev*10+rem;
    reverseNumber(num/10);




}

void main()
{
   int num;
   printf("Enter number:");
   scanf("%d",&num);
   int rev=reverseNumber(num);
   printf("Reversed number is %d",rev);


}
