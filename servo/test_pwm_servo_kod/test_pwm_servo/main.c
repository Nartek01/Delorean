/*
 * main.c
 *
 * Created: 2/5/2024 12:39:31 PM
 *  Author: Peter
 */ 

#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include "p2.h"
#include <math.h>


int main(void)
{
    setup_p2();
    /*uint16_t a = 0;
    uint16_t b = 0;
    uint16_t c = 0;
    uint16_t d = 0;
    uint16_t e = 0;*/
    
    while(1)
    {
        /*uint8_t sensor_reading_array [] {a, b, c, d, e};
        
        for (uint8_t i = 0; i < 4; i++)
        {
            sensor_reading_array[i] = read_analogue_input(0)        
        }*/
        
        /*uint16_t analogue_value = read_analogue_input(0);*/
       /* uint16_t av_divided = round(analogue_value / 1.023);*/
        
        
        /*uint16_t on_value = 1000+(round(sensor_reading_array[2]*1.023));
        uint16_t off_value = 19000-(round(sensor_reading_array[2]*1.023));*/
        
        /*PWM-signal i en for-loop med en wait emellan*/
        
        /*uint16_t on_value = 1000+(round(read_analogue_input(0)/1.023));
        uint16_t off_value = 19000-(round(read_analogue_input(0)/1.023));*/
        
        for (uint8_t i = 0; i < 10; i++)
        {
            write_digital_output_portb(1,1);
            wait(1500);
            write_digital_output_portb(1,0);
            wait(18500);
        }
    }
}

/*
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}*/

// Function to perform Selection Sort
/*
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    
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
}*/

// Function to print an array
/*
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}*/