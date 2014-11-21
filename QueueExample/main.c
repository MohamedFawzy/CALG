//
//  main.c
//  QueueExample
//
//  Created by Mohamed Fawzy on 11/21/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define QUEUESIZE 20
#define YES 1
#define NO 0
struct Queue{
    int front;
    int rear;
    int items[QUEUESIZE];
};
void enqueue(struct Queue *qptr, float x);
float dequeue(struct Queue *qptr);
void display(struct Queue *qptr);
int empty(struct Queue *qptr);
int full(struct Queue *qptr);
void clearQ(struct Queue *qptr);
void menu();

int main(int argc, const char * argv[]) {
    int choice;
    float x;
    struct Queue q;
        q.front=0;
        q.rear=-1;
    do{
        menu();
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%f",&x);
                enqueue(&q, x);
                break;
            case 2:
                x= dequeue(&q);
                printf("\nRemoved item :%f\n",x);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                clearQ(&q);
                break;
            default:
                printf("\nWrong entry, Try again !\n");
                break;
        }
    }while (choice !=5);
    return 0;
}

void menu(){
    printf("Press 1 to enqueue\n");
    printf("press 2 to dequeue\n");
    printf("press 3 to display\n");
    printf("press 4 to clear\n");
    printf("Press 5 to quite\n");
    printf("\n\nEnter your choice\n");
}

int empty(struct Queue *qptr){
    return (qptr->front > qptr->rear) ? YES : NO;
}

int full(struct Queue *qptr){
    return (qptr->rear == QUEUESIZE-1) ? YES : NO;
}


void enqueue(struct Queue *qptr, float x){
    if (full(qptr)) {
        printf("Queue overflow\n");
        exit(1);
    }else{
        qptr->rear++;
        qptr->items[qptr->rear]=x;
    }
}

float dequeue(struct Queue *qptr){
    if(empty(qptr)){
        printf("Queue underflow\n");
        exit(1);
    }else{
        float pp = qptr->items[qptr->front];
        qptr->front++;
        return pp;
    }
}

void clearQ(struct Queue *qptr){
    qptr->front=0;
    qptr->rear=-1;
    printf("Queue now is empty\n");
}

void display(struct Queue *qptr){
    int i;
    if (empty(qptr)) {
        printf("Queue is empty\n");
        exit(1);
    }else{
        printf("Queue is \n");
        for (i=qptr->front; i<=qptr->rear; i++) {
            printf("%d",qptr->items[i]);
        }
        printf("\n");
    }
    
}