#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct {
    int priority;
    char data[50];
} Element;

typedef struct {
    Element elements[SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *q) {
    q->size = 0;
}

int isEmpty(PriorityQueue *q) {
    return q->size == 0;
}

int isFull(PriorityQueue *q) {
    return q->size == SIZE;
}

void enqueue(PriorityQueue *q, int priority, const char *data) {
    if (isFull(q)) {
        printf("Hang doi da day\n");
        return;
    }

    int i = q->size - 1;
    while (i >= 0 && q->elements[i].priority > priority) {
        q->elements[i + 1] = q->elements[i];
        i--;
    }

    q->elements[i + 1].priority = priority;
    strcpy(q->elements[i + 1].data, data);
    q->size++;

    printf("Them phan tu (%d, \"%s\"): Hang doi khong rong\n", priority, data);
}

void dequeue(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }

    Element highestPriorityElement = q->elements[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->elements[i] = q->elements[i + 1];
    }
    q->size--;

    printf("Lay ra phan tu: \"%s\"\n", highestPriorityElement.data);
}

void printQueue(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Trang thai hang doi: \n");
    for (int i = 0; i < q->size; i++) {
        printf("(%d, \"%s\")\n", q->elements[i].priority, q->elements[i].data);
    }
}

int main() {
    PriorityQueue q;
    initQueue(&q);

    enqueue(&q, 2, "Task A");
    printQueue(&q);

    enqueue(&q, 1, "Task B");
    printQueue(&q);

    enqueue(&q, 3, "Task C");
    printQueue(&q);

    printf("Phan tu uu tien cao nhat: \"%s\" (uu tien %d)\n", q.elements[0].data, q.elements[0].priority);
    dequeue(&q);
    printQueue(&q);

    printf("Phan tu uu tien cao nhat: \"%s\" (uu tien %d)\n", q.elements[0].data, q.elements[0].priority);
    dequeue(&q);
    printQueue(&q);

    return 0;
}

