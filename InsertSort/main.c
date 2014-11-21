//
//  main.c
//  InsertSort
//
//  Created by Mohamed Fawzy on 11/10/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define SIZE 5
int main(int argc, const char * argv[]) {
    
    int array[SIZE] = {5,3,2,1,4};
    
    for (int i=0; i<=SIZE-1; i++) {
        printf("%4d",array[i]);
    }
    
    printf("\n");
    int key=0,i=0,j=0;
    for (i=1; i<=SIZE-1; i++) {
        key = array[i];
        j = i-1;
        while (i>=0 && array[j] > key) {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
    
    printf("After sorted\n");
    
    for (int i=0; i<=SIZE-1; i++) {
        printf("%4d",array[i]);
    }
    
    printf("\n");
    return 0;
}
