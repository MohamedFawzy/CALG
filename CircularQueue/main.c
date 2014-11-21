//
//  main.c
//  CircularQueue
//
//  Created by Mohamed Fawzy on 11/21/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define QUEUESIZE 10
struct Queue{
    int front;
    int rear;
    int items[QUEUESIZE];
};

void enqueue(struct Queue *qptr, char x);
char dequeue(struct Queue *qptr);
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Queue q;
        q.front=QUEUESIZE-1;
        q.rear=QUEUESIZE-1;
    
    printf("Enter string for circular queue\n");
    char a[20];
    scanf("%s",a);
    char p;
    for (int i=0; a[i] != '\0'; i++) {
        p = a[i];
        enqueue(&q, p);
        printf("%c\t",p);
    }
    printf("\n");
    char pp = dequeue(&q);
    printf("%c", pp);
    
    return 0;
}

void enqueue(struct Queue *qptr, char x){
    if(qptr->rear == QUEUESIZE-1){
        qptr->rear=0;
    }else{
        qptr->rear++;
    }
    if(qptr->rear == qptr->front){
        printf("Queue overflow\n");
        exit(1);
    }
    
    qptr->items[qptr->rear]=x;
}

char dequeue(struct Queue *qptr){
    char pp = qptr->items[qptr->front];
    if(qptr->front == qptr->rear){
        printf("Queue underflow\n");
        exit(1);
    }
    if(qptr->front == QUEUESIZE-1){
        qptr->front=0;
    }else{
        qptr->front++;
    }
    return pp;
}
