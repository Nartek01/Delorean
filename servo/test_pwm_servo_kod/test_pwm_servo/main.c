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
    
    
    uint8_t range_low = 100;
    uint16_t range_medium = 140;
    uint16_t range_high = 150;
    
    while(1)
    {
        perf_sensor_right_reading();
        perf_sensor_left_reading();
        
        if (c_r > c_l)
        {
            /*if (c_r >  range_low && c_r < range_high)
            {
                servo_function(25);
            }
            else if ((c_r > range_high && c_r < 1023))
            {
                servo_function(40);
            }*/
            
            if (c_r >  range_high )
            {
                servo_function(40);
            }
            
            else if (c_r > range_medium && c_r < range_high)
            {
                servo_function(20);
            }
            else if (c_r > range_low && c_r < range_medium)
            {
                servo_function(10);
            }
            else
            {
                servo_function(0);
            }
        }
        
        else if (c_r < c_l)
        {
            
            if (c_l >  range_high )
            {
                servo_function(-40);
            }
            
            else if (c_l > range_medium && c_l < range_high)
            {
                servo_function(-20);
            }
            else if (c_l > range_low && c_l < range_medium)
            {
                servo_function(-10);
            }
            else
            {
                servo_function(0);
            }
        }
    }
}

