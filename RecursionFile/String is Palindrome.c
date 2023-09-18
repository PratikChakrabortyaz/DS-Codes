#include<stdio.h>
#include<string.h>

int stringPalindrome(char *str1,int low,int high)
{


  if(low>=high)
  {

      return 1;
  }

  if(str1[low]==str1[high])
  {
      return stringPalindrome(str1,low+1,high-1);
  }
  return 0;


}

void main()
{
    char str1[20];
    printf("Enter string:");
    scanf("%s",str1);
    int palin=stringPalindrome(str1,0,strlen(str1)-1);
    if(palin)
    {
        printf("String is palindrome");
    }
    else{
        printf("String is not palindrome");
    }


}

