//
//  main.c
//  CircularQueueExample2
//
//  Created by Mohamed Fawzy on 11/21/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define YES 1
#define NO 0
#define CRICULARQUEUESIZE 20
struct CircularQueue{
    int front;
    int rear;
    int items[CRICULARQUEUESIZE];
};
void enqueue(struct CircularQueue *qptr, int x);
int dequeue(struct CircularQueue *qptr);
int empty(struct CircularQueue *qptr);
int full(struct CircularQueue *qptr);
int QueueSearch(struct CircularQueue *qptr, int x);
void display(struct CircularQueue *qptr);
void clearQ(struct CircularQueue *qptr);
void menu();
int main(int argc, const char * argv[]) {
    int x,choice;
    struct CircularQueue cq;
        cq.front = CRICULARQUEUESIZE-1;
        cq.rear = CRICULARQUEUESIZE-1;
    
    do{
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter elements to enqueue\n");
                scanf("%d", &x);
                enqueue(&cq, x);
                break;
            case 2:
                x = dequeue(&cq);
                printf("\n%d is dequeue\n",x);
                break;
            case 3:
                display(&cq);
                break;
            case 4:
                clearQ(&cq);
                break;
            case 5:
                printf("Enter element you need to search for \n");
                scanf("%d",&x);
                int pos = QueueSearch(&cq, x);
                printf("The key element %d found at index %d\n", x, pos);
                break;
            default:
                printf("\nWrong entry, Try again !\n");
                break;
        }
    }while (choice != 6);
    return 0;
}


int empty(struct CircularQueue *qptr){
    return (qptr->front == qptr->rear) ? YES : NO;
}

int full(struct CircularQueue *qptr){
    return (qptr->rear == qptr->front) ? YES : NO;
}

void enqueue(struct CircularQueue *qptr, int x){
    if (qptr->rear == CRICULARQUEUESIZE-1) {
        qptr->rear=0;
    }else{
        qptr->rear++;
        qptr->items[qptr->rear]=x;
    }
    
    if (full(qptr)) {
        printf("Queue overflow\n");
        exit(1);
    }
    
    printf("inserted new item %d\n", x);
}

int dequeue(struct CircularQueue *qptr){
    if(empty(qptr)){
        printf("Queue underflow\n");
        exit(1);
    }
    if(qptr->front == CRICULARQUEUESIZE-1){
        qptr->front=0;
    }else{
        qptr->front++;
    }
    int pp = qptr->items[qptr->front];
    return pp;
}

void clearQ(struct CircularQueue *qptr){
    qptr->front = CRICULARQUEUESIZE-1;
    qptr->rear=CRICULARQUEUESIZE-1;
    printf("Queue now is empty\n");
}

void display(struct CircularQueue *qptr){
    int f,r;
    f = qptr->front;
    r = qptr->rear;
    while (qptr->front != qptr->rear) {
        if (qptr->front == CRICULARQUEUESIZE-1) {
            qptr->front=0;
        }else{
            qptr->front++;
        }
        printf("%d", qptr->items[qptr->front]);
        printf("\n");
        //qptr->front=f;
        //qptr->rear=r;
    }
}

int QueueSearch(struct CircularQueue *qptr, int searchKey){
    int position=-1,f;
    f=qptr->front;
    while (qptr->front != qptr->rear) {
        if (qptr->front == CRICULARQUEUESIZE-1) {
            qptr->front=0;
        }else{
            qptr->front++;
        }
        if (qptr->items[qptr->front]== searchKey) {
            position = qptr->front;
            qptr->front=f;
            return position;
        }
    }
    
    qptr->front=f;
    return position;
}

void menu(){
    printf("Press 1 to enqueue\n");
    printf("Press 2 to dequeue\n");
    printf("Press 3 to display\n");
    printf("Press 4 to clear\n");
    printf("Press 5 to search\n");
    printf("press 6 to quit\n");

}

