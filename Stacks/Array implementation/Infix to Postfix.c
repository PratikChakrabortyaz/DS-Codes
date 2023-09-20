/*infix to postfix*/

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

void infixToPostfix(char *exp,char *postfix)
{
    Stack st;
    initialize(&st);
    int length=strlen(exp);
    int j=0;
    for(int i=0;i<length;i++)
    {
        char token=exp[i];
        if(isalnum(token))
        {
            postfix[j++]=token;
        }
        else if(token=='(')
        {
            push(&st,token);
        }
        else if(token==')')
        {
            while(!isEmpty(&st)&&st.stack[st.top]!='(')
            {
                postfix[j++]=pop(&st);
            }
            pop(&st);
        }
        else
        {
            while(!isEmpty(&st) && precedence(token)<=precedence(st.stack[st.top]))
            {
                postfix[j++]=pop(&st);
            }
            push(&st,token);
        }
    }
    while(!isEmpty(&st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';

}



void main()
{
    char exp[10];
    char postfix[10];
    printf("Enter infix expression:");
    scanf("%s",&exp);
    infixToPostfix(exp,postfix);
    printf("%s",postfix);





}
