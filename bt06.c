#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int data[SIZE];
    int front;
    int rear;
    int count;
} Deque;

void initDeque(Deque *deque) {
    deque->front = 0;
    deque->rear = -1;
    deque->count = 0;
}

int isEmpty(Deque *deque) {
    return deque->count == 0;
}

int isFull(Deque *deque) {
    return deque->count == SIZE;
}

void addFront(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Hang doi da day\n");
        return;
    }

    deque->front = (deque->front - 1 + SIZE) % SIZE;
    deque->data[deque->front] = value;
    deque->count++;
    printf("Them phan tu vao dau: %d\n", value);
}

void addRear(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Hang doi da day\n");
        return;
    }

    deque->rear = (deque->rear + 1) % SIZE;
    deque->data[deque->rear] = value;
    deque->count++;
    printf("Them phan tu vao cuoi: %d\n", value);
}

void removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }

    int value = deque->data[deque->front];
    deque->front = (deque->front + 1) % SIZE;
    deque->count--;
    printf("Lay ra phan tu tu dau: %d\n", value);
}

void removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }

    int value = deque->data[deque->rear];
    deque->rear = (deque->rear - 1 + SIZE) % SIZE;
    deque->count--;
    printf("Lay ra phan tu tu cuoi: %d\n", value);
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Hang doi hien tai: [");
    for (int i = 0; i < deque->count; i++) {
        int index = (deque->front + i) % SIZE;
        printf("%d", deque->data[index]);
        if (i < deque->count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    addFront(&deque, 10);
    printDeque(&deque);

    addRear(&deque, 20);
    printDeque(&deque);

    addFront(&deque, 5);
    printDeque(&deque);

    removeFront(&deque);
    printDeque(&deque);

    removeRear(&deque);
    printDeque(&deque);

    return 0;
}

