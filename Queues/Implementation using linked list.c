#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initialize(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed. Queue full.\n");
        return;
    }
    newNode->data = ele;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue empty.\n");
        return 0;
    }

    int dequeuedElement = q->front->data;
    Node* temp = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return dequeuedElement;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue contents are empty.\n");
    } else {
        Node* current = q->front;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main() {
    Queue q;
    initialize(&q);

    dequeue(&q);
    enqueue(&q, 3);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 2);
    dequeue(&q);

    display(&q);

    // Clean up and free memory
    while (!isEmpty(&q)) {
        dequeue(&q);
    }

    return 0;
}
