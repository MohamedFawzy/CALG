//
//  main.c
//  LinearSearch
//
//  Created by Mohamed Fawzy on 10/12/14.
//  Copyright (c) 2014 Mohamed fawzy. All rights reserved.
// find specific value in array / dictonary whatever using linear search , sequnatil search
// worest case senairo Big Oh ( keyword, value ) in last index
//

#include <stdio.h>
#define SIZE 10
int linearSearch(int [], int);
int main()
{
    int a[SIZE] = {9,4,5,1,7,78,22,15,96,45}, key, pos;
    printf("Enter the search key :\n");
    scanf("%d", &key);
    pos = linearSearch(a,key);
    if(pos == -1)
        printf("the search key is not in array\n");
    else
        printf("the search key %d is at location %d\n", key, pos);
    
    return 0;
}

int linearSearch(int a[], int searchKey)
{
    int i;
    for (i=0; i<=SIZE-1; i++) {
        if(a[i] == searchKey){
            return i;
        }
    }
    return -1;
}
