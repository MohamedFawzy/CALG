//
//  main.c
//  PlainDromeUsingStack
//
//  Created by Mohamed Fawzy on 11/20/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define SIZE 25
struct Stack{
    int count;
    int top;
    int items[SIZE];
};

void push(struct Stack *sptr, char x);
char pop(struct Stack *sptr);

int main(int argc, const char * argv[]) {
    struct Stack s;
        s.top=-1;
        s.count=0;
    
    char a[20];
    char p;
    
    printf("Enter a string\n");
    gets(a);
    for (int i=0; a[i] != '\0'; i++) {
        p = a[i];
        push(&s, p);
    }
    int size =s.count;
    int check=0;
    for (int i=0; i<=size-1; i++) {
        p = pop(&s);
        if(p != a[i]){
            check++;
        }
    }
    
    
    if (check==0) {
        printf("The string %s is plaindrom \n", a);
    }else{
        printf("The string %s is not plaindrom \n", a);
    }
    
    return 0;
}


void push(struct Stack *sptr, char s){
    
    if(sptr->top == SIZE-1){
        printf("Stack is full \n");
        return;
    }else{
        sptr->top++;
        sptr->items[sptr->top] = s;
        sptr->count++;
    }
    
}

char pop(struct Stack *sptr){
    char pp = sptr->items[sptr->top];
    if(sptr->top == -1){
        printf("Stack is empty\n");
        exit(1);
    }else{
        sptr->top--;
        sptr->count--;
        return pp;
    }

}