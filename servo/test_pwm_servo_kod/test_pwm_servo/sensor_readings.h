/*
* sensor_readings.h
*
* Created: 2024-03-04 11:37:26
*  Author: Peter
*/

void swap();
void selectionSort();
void perf_sensor_right_reading ();



#ifndef SENSOR_READINGS_H_
#define SENSOR_READINGS_H_

/************************************************************************/
/* uint16_t read_analogue_input(uint8_t input_number)                   */
/*                                                                      */
/* Argument:                                                            */
/* uint8_t input_number                                                 */
/* Reprecenterar den ingång (0 - 5) som skall läsas av                  */
/*                                                                      */
/* Return:                                                              */
/* Det returnerande värdet är ett 16-bitars uint-tal mellan 0 - 1023    */
/************************************************************************/

uint16_t read_analogue_input(uint8_t input_number) {
    ADMUX = ((1 << REFS0) | (1 << REFS1) | input_number); // REFS0 = 1 & REFS1 = 1 blir "internal 1.1V Voltage Reference with external capacitor at AREF pin"
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));  //ADEN: enable, ADSC: ADC start conversion,  ADPS0:2 : prescaler för att matcha extern clock med multiplex clocka
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return ADC;
}

/*Variabler för front-arrayens data*/
uint16_t a;
uint16_t b;
uint16_t c;
uint16_t d;
uint16_t e;

uint16_t sensor_reading_arr [] = {0,0,0,0,0};
    

void perf_sensor_front_reading ()
{

    for (uint8_t i = 0; i < 5; i++)
    {
        sensor_reading_arr[i] = read_analogue_input(0);
    }
    
    uint8_t n = sizeof(sensor_reading_arr) / sizeof(sensor_reading_arr[0]);
    
    selectionSort(sensor_reading_arr, n);
    
    a = sensor_reading_arr[0];
    b = sensor_reading_arr[1];
    c = sensor_reading_arr[2];
    d = sensor_reading_arr[3];
    e = sensor_reading_arr[4];
    
}
#endif /* SENSOR_READINGS_H_ */