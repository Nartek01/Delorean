/*
 * pwm_servo.h
 *
 * Created: 2024-03-04 11:21:44
 *  Author: Peter
 */ 


#ifndef PWM_SERVO_H_
#define PWM_SERVO_H_


/*Funktion som tolkar om värdet till PWM-värde -50 -> 50*/
void servo_function (int8_t turning_value)
{
    OCR1AH = 0x00;
    OCR1AL = round((0.3*turning_value)+47);
}

void pwm_init ()
{
    DDRB |= (1<<1) | (1<<2);    // Sätter utgångar D9 och D10
    OCR1AH = 0x00;              //
    //OCR1AL = 47;                // Sätter duty cycle 47 i mitten, 32 längst åt höger, 62 längst åt *****
    //OCR1BL = 150;
    ICR1H = 0b00000010;         // Sätter högstavärdet den räknar till ICR1H = 0b00000010; + ICR1L = 0b01101111; = 50 Hz
    ICR1L = 0b01101111;         // Sätter högstavärdet den räknar till
    TCCR1A = 0xA2;              //
    TCCR1B = 0b00010100;        // första nibble sätter PWM-typen - sista nibble sätter prescaler (detta är 256 prescaler)
}


#endif /* PWM_SERVO_H_ */