//
//  main.c
//  median
//
//  Created by Mohamed Fawzy on 10/12/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
//

#include <stdio.h>
#define SIZE 10
void bubbleSort(int []);
int getMedian(int []);
int main()
{
    int a[SIZE] = {9, 4, 5, 1, 7, 78, 22, 15, 96, 45}, i;
    printf("sorted array :\n");
    for(i=0; i<= SIZE-1; i++){
        bubbleSort(a);
        printf("%10d ", a[i]);
    }
    printf("\n");
    int result = getMedian(a);
    printf("result is %d", result);
    printf("\n");
    return 0;
}


void bubbleSort(int a[])
{
    int i, pass, hold;
    for (pass=1; pass<= SIZE-1; pass++) {
        for (i=0; i<=SIZE-2; i++) {
            if (a[i] > a[i+1]) {
                hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
            }
        }
    }
    
}

int getMedian(int a[])
{
    int middleIndex = (SIZE - 1) / 2;
    return a[middleIndex];
}