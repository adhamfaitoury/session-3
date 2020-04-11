/*
 * File:   main.c
 * Author: M3MO
 *
 * Created on 11 ?????, 2020, 02:18 ?
 */


#include <xc.h>

#define  BUTTON2         2
#define  LED2            3
#define  BUTTON0         0
#define  LED0            2
#define  BUTTON1         4
#define  LED1            7
#define  out             0
#define  in              1

#define portA           1
#define portB           2
#define portC           3
#define portD           4

int main(void) {

    // Data Direction Register
    DDRA = 0xFF;
    PORTA = 0x00;
    DDRC = 0xFF;
    PORTC = 0x00;
    DDRB &= ~(1 << BUTTON2); // INPUT PIN.
    DDRD |= (1 << LED2);

    while (1) {
        // Loop until power OFF
        if (isPressedD(BUTTON2)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED2, portD);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED2, portD);
        }
        if (isPressedB(BUTTON0)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED0, portC);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED0, portC);
        }
        if (isPressedB(BUTTON1)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED1, portC);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED1, portC);
        }
    }
}
