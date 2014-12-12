//
//  main.c
//  Queue
//
//  Created by Mohamed Fawzy on 11/21/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define QUEUESIZE 50
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
        q.front=0;
        q.rear=-1;
    
    printf("Enter string to queue\n");
    char input[20];
    scanf("%s",input);
    char p;
    for (int i=0; input[i] != '\0'; i++) {
        p = input[i];
        enqueue(&q, p);
        printf("%c\t",p);
    }
    printf("Removed from queue\t");
    char pp = dequeue(&q);
    printf("%c",pp);
    printf("\n");
    return 0;
}


void enqueue(struct Queue *qptr, char x){
    if (qptr->rear == QUEUESIZE-1) {
        printf("Queue is full\n");
        return;
    }else{
        qptr->rear++;
        qptr->items[qptr->rear]=x;
    }
}

char dequeue(struct Queue *qptr){
    char p;
    if (qptr->front > qptr->rear) {
        printf("queue is empty\n");
        exit(1);
    }else{
        p = qptr->items[qptr->front];
        qptr->front++;
        return p;
    }
}

/**
 * shift all rear element in queue and free memory allocation for front then set old queue in front[0]
 *
 */

/*char dequeue(struct Queue *qptr){
    char pp = qptr->items[qptr->front];
    int i=0;
    if (qptr->front > qptr->rear) {
        printf("Queue is empty\n");
        exit(1);
    }else{
        for (i=1; i<=qptr->rear; i++) {
            qptr->items[i-1]=qptr->items[i];
            qptr->rear--;
        }
        return pp;
    }
}*/



