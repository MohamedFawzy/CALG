//
//  main.c
//  CircularQueueEx1
//
//  Created by Mohamed Fawzy on 11/21/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define QUEUESIZE 50
#define YES 1
#define NO 0
struct Queue{
    int front;
    int rear;
    int items[QUEUESIZE];
};
void enqueue(struct Queue *qptr, int x);
int dequeue(struct Queue *qptr);
int empty(struct Queue *qptr);
int full(struct Queue *qptr);
int main(int argc, const char * argv[]) {
    char operation;
    int x;
    struct Queue q;
        q.front = QUEUESIZE-1;
        q.rear=QUEUESIZE-1;
    do{
        printf("Queue operation type I(nsert) D(elete) E(xit)\n");
        scanf("%c",&operation);
        switch (operation) {
            case 'I':
                printf("Enter element to enqueue\n");
                scanf("%d",&x);
                enqueue(&q, x);
                break;
            case 'D':
                x = dequeue(&q);
                printf("\n%d is deleted\n",x);
                break;
            default:
                printf("Incorrect operation type");
                break;
        }
    }while (operation != 'E' && operation != 'e');
    
    return 0;
}

int full(struct Queue *qptr){
    return (qptr->rear == qptr->front) ? YES : NO;
}

int empty(struct Queue *qptr){
    return (qptr->front == qptr->rear) ? YES : NO;
}

void enqueue(struct Queue *qptr, int x){
    if (qptr->rear == QUEUESIZE-1) {
        qptr->rear=0;
    }else{
        qptr->rear++;
    }
    
    if(full(qptr)){
        printf("Queue overflow\n");
        exit(1);
    }
    
    qptr->items[qptr->rear] = x;
    printf("\n%d is inserted \n",x);
}

int dequeue(struct Queue *qptr){
    int pp = qptr->items[qptr->front];
    if(empty(qptr)){
        printf("Queue underflow\n");
        exit(1);
    }else if(qptr->front == QUEUESIZE-1){
        qptr->front=0;
    }else{
        qptr->front++;
    }
    return pp;
}

