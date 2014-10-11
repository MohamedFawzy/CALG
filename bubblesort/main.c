//
//  main.c
//  bubblesort
//
//  Created by Mohamed Fawzy on 10/11/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
// this program sorted an array using bubble sort algorithm in ascending order
//

#include <stdio.h>
#define SIZE 5
void bubbleSort(int []);
int main()
{
    int a[SIZE] = {2,1,5,3,2};
    int i;
    printf("The elements of the array before sorting: ");
    for(i=0;i<= SIZE-1; i++){
        printf("%4d", a[i]);
    }
    
    printf("\n The elements of the array after sorting: ");
    for(i=0; i<= SIZE-1; i++){
        bubbleSort(a);
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int a[])
{
    int i, pass, hold;
    for(pass=0; pass <= SIZE-1; pass++){
        for (i=0; i<=SIZE-2; i++) {
            if(a[i]> a[i+1]){
                hold = a[i];
                a[i]=a[i+1];
                a[i+1] = hold;
            }
        }
    }
}
