//
//  main.c
//  BinarySearch
//
//  Created by Mohamed Fawzy on 10/12/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
// binarysearch algorithm
// with bubblesort algorithm
//

#include <stdio.h>
#define SIZE 10
void bubbleSort(int []);
int binarySearch(int [], int);
int main()
{
    int a[SIZE] = {3,4,6,66,33,14,1,12,2,10},i,key,pos;
    // sort array first using bubble sort
    for (i=0; i<=SIZE-1; i++) {
        bubbleSort(a);
    }
    // binary search
    printf("Enter the search key\n");
    scanf("%d",&key);
    pos = binarySearch(a, key);
    if(pos == -1)
        printf("the search key is not in the array\n");
    else
        printf("the search key %d located in location %d\n", key, pos);
    
    return 0;
}



void bubbleSort(int a[])
{
    int i,pass, hold;
    for (pass=1; pass<=SIZE-1; pass++) {
        for (i=0; i<=SIZE-2; i++) {
            if(a[i] > a[i+1]){
                hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
            }
        }
    }
}

int binarySearch(int a[], int searchKey)
{
    int low=0, high = SIZE-1, middle;
    while (low <=high) {
        middle = (low+high)/2;
        if (searchKey == a[middle])
            return middle;
        else if (searchKey < a[middle])
            high = middle-1;
        else
            low = middle+1;
    }
    
    return -1;
}
