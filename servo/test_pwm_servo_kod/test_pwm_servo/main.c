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
        perf_sensor_left_reading();
        
        if (c_r > c_l)
        {
            if (c_r > 200)
            {
                servo_function(-25);
            }
            else
            {
                servo_function(0);
            }
        }
        
        else if (c_r < c_l)
        {
            
            if (c_l > 200)
            
            {
                servo_function(25);
            }
            else
            {
                servo_function(0);
            }
        }
    }
}

