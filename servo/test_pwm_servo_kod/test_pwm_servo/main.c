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
#include "p2.h"
#include <math.h>
#include "pwm_servo.h"

int main(void)
{
    setup_p2();
    pwm_init();
    while(1)
    {
        servo_function(0);
    }
}

