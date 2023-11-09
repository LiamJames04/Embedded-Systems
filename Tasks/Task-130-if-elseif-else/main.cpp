#include "uop_msb.h"
using namespace uop_msb;


DigitalIn ButtonC(PG_2, PullDown); //Button C
DigitalIn ButtonD(PG_3, PullDown); //Button D
BusIn bus(PG_0, PG_1);
int swVal;
DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        swVal = bus;
        //Test Button A
        if (bus[0] == 1){
            redLED = !redLED;    //Toggle RED led
            count = count+ ((count<99) ? 1:0);            //Increment count
            disp = count;       //Update display
        }
        if (bus[1]==1){
            redLED = !redLED;
            count=count-1; 
            disp = count;
        }
        if((bus[0]==1) && (bus[1]==1)){
            greenLED=1;
            count=0;
            disp=count;
        }
        if((count<0) || (count>99)){
            count=0;
            disp=count;
        }

        // Slow it down a bit (and debounce the switches)
       wait_us(100000);
       greenLED=0;
    }
}


