#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct{
	int data[SIZE];
	int front,rear;
}Queue;

void initQueue(Queue*q){
	q->front = -1;
	q->rear = -1;
}

void enqueue(Queue*q, int value){
	if(q->rear == SIZE -1){
		printf("Hang doi da day\n");
		return;
	}
	
	if(q->front == -1){
		q->front = 0;
	}
	
	q->rear++;
	q->data[q->rear] = value;
}

void printQueue(Queue*q){
	if (q->front == -1 || q->front > q->rear) {
    printf("Hang doi rong\n");
    return;
	}
	
	for(int i=q->front; i<= q->rear; i++){
		printf("%d-", q->data[i]);
	}
}

int main(){
	
	Queue q;
	initQueue(&q);
	
	enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Cac phan tu trong hang doi: ");
    printQueue(&q);
	
	return 0;
}
