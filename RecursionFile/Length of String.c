/*Static variable is used*/

#include<stdio.h>

int stringLength(int index,char *s)
{
    static int length;
    if(s[index]=='\0')
    {
        return 0;
    }
    else{
        length++;
        stringLength(index+1,s);
        return length;
    }

}

void main()
{
  char s[20];
  printf("Enter string:");
  scanf("%s",s);
  printf("Length of string is %d",stringLength(0,s));
}

