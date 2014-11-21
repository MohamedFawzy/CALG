//
//  main.c
//  Stack
//
//  Created by Mohamed Fawzy on 10/25/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define STACKSIZE 10
struct Stack
{
    int count;
    int top;
    int items[STACKSIZE];
};

void push(struct Stack *sptr, int x);

int main(int argc, const char * argv[]) {
    int p;
    struct Stack s;
        s.top=-1;
        s.count=0;
    
    for (int i=0; i<=STACKSIZE-1; i++) {
        push(&s, s.items[i] = i);
    }
    
    for (int i=0; i<STACKSIZE-1; i++) {
        p = pop(&s);
        printf("%d\t", p);
    }
    return 0;

}

void push(struct Stack *sptr, int x)
{
    if(sptr->top == STACKSIZE-1){
        printf("Stack is full\n");
        return;
    }else{
        sptr->top++;
        sptr->items[sptr->top] = x;
        sptr->count++;
    }
}


int pop(struct Stack *sptr)
{
    int pp;
    if(sptr->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        pp = sptr->items[sptr->top];
        sptr->top--;
        sptr->count--;
        return pp;
    }
}