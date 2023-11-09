#include "mbed.h"


// BusIn bus(PG_0, PG_1, PG_2, PG_3);
BusIn bus(PG_0, PG_1, PG_2, PG_3);
DigitalOut redLED(PC_2); //Red Traffic 1
int buttons;
// main() runs in its own thread in the OS
int main()
{
    // Turn OFF the red LED
    redLED = 0;

    // bus[2].mode(PinMode::PullDown);
    // bus[3].mode(PinMode::PullDown);
    bus[2].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    
    while (true) {
        
        //Wait for ALL buttons to be pressed
        do {
          //reads all button outputs
          buttons=bus;  
        }while(buttons<15);

        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        do{
            //reads all button outputs
            buttons=bus;
        }while(buttons>0);
        //Wait for noise to settle
        wait_us(10000);        

    }
}


