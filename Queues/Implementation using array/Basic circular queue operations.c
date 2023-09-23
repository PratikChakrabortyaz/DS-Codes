/*Basic circular queue operations. Not menu driven*/
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
    return ((q->front==q->rear+1)||(q->front==0&&q->rear==MAX-1));
}

void enqueue(Queue *q, int ele) {
    if (isFull(q)) {
        printf("\nQueue full\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear=(q->rear+1)%MAX;
        q->queue[q->rear] = ele;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue empty\n");
    } else {
        int dequeuedElement = q->queue[(q->front)];
        if (q->front > q->rear) {
            initialize(q);
        }
        else
        {
            q->front=(q->front+1)%MAX;
        }
        return dequeuedElement;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue contents empty\n");
    } else {
        int i = q->front;
        do {
            printf("%d\n", q->queue[i]);
            i = (i + 1) % MAX;
        } while (i != (q->rear + 1) % MAX);
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
    enqueue(&q, 3);
    display(&q);

}

