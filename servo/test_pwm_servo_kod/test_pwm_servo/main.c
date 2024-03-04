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
    uint16_t a = 0;
    uint16_t b = 0;
    uint16_t c = 0;
    uint16_t d = 0;
    uint16_t e = 0;
    
    while(1)
    {
        uint8_t sensor_reading_array [] {a, b, c, d, e};
        
        for (uint8_t i = 0; i < 4; i++)
        {
            sensor_reading_array[i] = read_analogue_input(0)        
        }
    }
}




