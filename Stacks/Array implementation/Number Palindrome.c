/*Check if number is palindrome using stack*/

#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 50
#include<string.h>

typedef struct {

    int top;
    char stack[MAX_SIZE];
}Stack;
void initialize(Stack *st)
{
    st->top=-1;
}
bool isEmpty(Stack *st)
{
    return (st->top==-1);
}

bool isFull(Stack *st)
{
    return(st->top==MAX_SIZE-1);
}

char push(Stack *st,char ele)
{
    if(isFull(st))
    {
        printf("\nStack overflow");
    }
    else{
        st->stack[++(st->top)]=ele;
    }
}

char pop(Stack *st)
{
    if(isEmpty(st))
    {
        printf("\nStack underflow");
        return 0;
    }
    else{
        return st->stack[(st->top)--];
    }
}

void display(Stack *st)
{
    if(isEmpty(st))
    {
        printf("\nStack contents are empty");
    }
    else{
        for(int i=0;i<=(st->top);i++)
        {
            printf("\n%d",st->stack[i]);
        }
    }
}
void main()
{
    Stack st;
    initialize(&st);
    int found=1;
    char num[10];
    printf("Enter number:");
    scanf("%s",&num);
    for(int i=0;i<strlen(num);i++)
    {
        char ch=num[i];
        push(&st,ch);
    }

        for(int i=0;i<strlen(num);i++)
        {
            if(num[i]!=pop(&st))
            {
                found=0;
                break;
            }
        }
    if(found)
    {
        printf("Number is palindrome");
    }
    else{
        printf("Number is not palindrome");
    }




}
