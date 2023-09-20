*prefix expression evaluation*/

#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 50
#include<string.h>
#include<ctype.h>

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


int evalPrefix(char *exp)
{
    Stack st;
    initialize(&st);
    int length=strlen(exp);
    for(int i=length-1;i>=0;i--)
    {
        char token=exp[i];
        if(isdigit(token))
        {
            push(&st,token-'0');
        }
        else{
            int operand1=pop(&st);
            int operand2=pop(&st);
            switch(token)
            {
                case '+':
                    push(&st,operand1+operand2);
                    break;
                case '-':
                    push(&st,operand1-operand2);
                    break;
                case '*':
                    push(&st,operand1*operand2);
                    break;
                case '/':
                    push(&st,operand1/operand2);
                    break;

            }
        }
    }
   return pop(&st);
}
void main()
{
    char exp[10];
    printf("Enter prefix expression:");
    scanf("%s",&exp);
    printf("%d",evalPrefix(exp));
}
