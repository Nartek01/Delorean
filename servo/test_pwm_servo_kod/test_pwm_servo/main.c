/*
* main.c
*
* Created: 2/5/2024 12:39:31 PM
*  Author: Peter
*/

#define F_CPU 16000000UL
#include <xc.h>
#include <stdint.h>
#include <util/delay.h>
#include <math.h>
#include "pwm_servo.h"
#include "sensor_readings.h"

int main(void)
{
    pwm_init();
    
    while(1)
    {
        perf_sensor_right_reading();
        
        if (c > 10)
        {
            servo_function(-50);
        }
        else
        {
            servo_function(0);
        }
    }
}

