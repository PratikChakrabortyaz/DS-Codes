#include<stdio.h>

void stringCopy(char *str1,char *str2,int index)
{
   if(str1[index]!='\0')
   {
       str2[index]=str1[index];
       stringCopy(str1,str2,index+1);
   }

}

void main()
{
    char str1[20],str2[20];
    printf("Enter string to be copied:");
    scanf("%s",str1);
    stringCopy(str1,str2,0);
    printf("Original string is %s",str1);
    printf("\nCopied string is %s",str2);
}
