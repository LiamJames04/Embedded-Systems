#include "mbed.h"
DigitalOut redLED(PC_2);
DigitalOut yellowLED(PC_3);
DigitalOut greenLED(PC_6);

// main() runs in its own thread in the OS
int main()
{

    while(true){

        redLED=1;
        yellowLED=1;
        greenLED=1;
        wait_us(2000000);

        redLED=0;
        yellowLED=0;
        greenLED=0;
        wait_us(20000);
        //Turns on red light
        redLED=1;
        wait_us(2000000);

        //Turns on red and yellow light
        redLED=1;
        yellowLED=1;
        wait_us(2000000);

        //Turns on green light + Turns off red and yellow light
        redLED=0;
        yellowLED=0;
        greenLED=1;
        wait_us(2000000);

        //Turns off green light
        greenLED=0;
        

        int count=0;
        while(count<4){
        printf("count=%d\n",count);
        yellowLED=1;
        wait_us(250000);
        yellowLED=0;
        wait_us(250000);
        count= count + 1;}
        
    }
    
   
    
  
}

