/*Basic stack operations using array. Not menu driven*/

#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 3

typedef struct {

    int top;
    int stack[MAX_SIZE];
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

void push(Stack *st,int ele)
{
    if(isFull(st))
    {
        printf("\nStack overflow");
    }
    else{
        st->stack[++(st->top)]=ele;
    }
}

int pop(Stack *st)
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
    push(&st,3);
    pop(&st);
    pop(&st);
    push(&st,5);
    push(&st,7);
    push(&st,10);
    push(&st,9);
    pop(&st);
    display(&st);


}
