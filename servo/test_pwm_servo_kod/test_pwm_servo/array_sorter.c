/*
 * filter.c
 *
 * Created: 2024-03-04 10:26:09
 *  Author: Peter
 */ 

#include <stdint.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}



/*
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}*/

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    uint8_t i, j, min_idx;
    
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        if (arr[j] < arr[min_idx])
        min_idx = j;
        
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

