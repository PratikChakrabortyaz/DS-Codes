/*Basic linear queue operations. Not menu driven*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 3

typedef struct {
    int rear;
    int front;
    int queue[MAX];
} Queue;

void initialize(Queue *q) {
    q->rear = -1;
    q->front = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int ele) {
    if (isFull(q)) {
        printf("\nQueue full\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->queue[++(q->rear)] = ele;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue empty\n");
    } else {
        int dequeuedElement = q->queue[(q->front)++];
        if (q->front > q->rear) {
            initialize(q);
        }
        return dequeuedElement;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue contents empty\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n", q->queue[i]);
        }
    }
}

void main() {
    Queue q;
    initialize(&q);
    dequeue(&q);
    enqueue(&q, 3);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 2);
    dequeue(&q);
    display(&q);

}

