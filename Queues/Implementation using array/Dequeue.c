/*Basic dequeue operations. Not menu driven*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 4

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Dequeue;

void initialize(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool isEmpty(Dequeue *dq) {
    return dq->front == -1;
}

bool isFull(Dequeue *dq) {
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1));
}

void enqueueFront(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot enqueue at the front.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = value;
}

void enqueueRear(Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot enqueue at the rear.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
}

int dequeueFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot dequeue from the front.\n");
    }

    int value = dq->arr[dq->front];

    if (dq->front == dq->rear) {
        // If there's only one element in the dequeue, reset it
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    return value;
}

int dequeueRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot dequeue from the rear.\n");
        return -1; // Return a sentinel value to indicate an empty dequeue
    }

    int value = dq->arr[dq->rear];

    if (dq->front == dq->rear) {
        // If there's only one element in the dequeue, reset it
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }

    return value;
}

void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Dequeue contents: ");
    int i = dq->front;
    do {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear && i != dq->front) {
            break; // Prevent an infinite loop when there's only one element
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (dq->rear + 1) % MAX_SIZE);
    printf("\n");
}

void main() {
    Dequeue dq;
    initialize(&dq);

    enqueueFront(&dq, 2);
    enqueueFront(&dq, 1);
    enqueueRear(&dq, 3);
    enqueueRear(&dq, 4);
    dequeueFront(&dq);
    enqueueFront(&dq,7);

    display(&dq); 

    dequeueRear(&dq);  

    display(&dq); 


}
