#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initialize(Stack* st) {
    st->top = NULL;
}

bool isEmpty(Stack* st) {
    return (st->top == NULL);
}

void push(Stack* st, int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed. Stack overflow");
        return;
    }
    newNode->data = ele;
    newNode->next = st->top;
    st->top = newNode;
}

int pop(Stack* st) {
    if (isEmpty(st)) {
        printf("\nStack underflow");
        return 0;
    }
    Node* temp = st->top;
    int poppedValue = temp->data;
    st->top = temp->next;
    free(temp);
    return poppedValue;
}

void display(Stack* st) {
    if (isEmpty(st)) {
        printf("\nStack contents are empty");
    } else {
        Node* current = st->top;
        while (current != NULL) {
            printf("\n%d", current->data);
            current = current->next;
        }
    }
}

int main() {
    Stack st;
    initialize(&st);
    push(&st, 3);
    pop(&st);
    pop(&st);
    push(&st, 5);
    push(&st, 7);
    push(&st, 10);
    push(&st, 9);
    pop(&st);
    display(&st);

    return 0;
}




