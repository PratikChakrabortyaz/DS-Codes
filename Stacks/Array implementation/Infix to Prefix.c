/* infix to prefix*/

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

int precedence(char token)
{
    switch(token)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
    }
    return 0;
}

void infixToPrefix(char *exp,char *prefix)
{
    Stack st;
    initialize(&st);
    int length=strlen(exp);
    int j=0;
    exp=strrev(exp);
    for(int i=0;i<length;i++)
    {
        char token=exp[i];
        if(isalnum(token))
        {
            prefix[j++]=token;
        }
        else if(token=='(')
        {
            push(&st,token);
        }
        else if(token==')')
        {
            while(!isEmpty(&st)&&st.stack[st.top]!='(')
            {
                prefix[j++]=pop(&st);
            }
            pop(&st);
        }
        else
        {
            while(!isEmpty(&st) && precedence(token)<=precedence(st.stack[st.top]))
            {
                prefix[j++]=pop(&st);
            }
            push(&st,token);
        }
    }
    while(!isEmpty(&st))
    {
        prefix[j++]=pop(&st);
    }
    prefix=strrev(prefix);

}



void main()
{
    char exp[10];
    char prefix[10];
    printf("Enter infix expression:");
    scanf("%s",&exp);
    infixToPrefix(exp,prefix);
    printf("%s",prefix);





}
