#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{
    printf("\nTASK-112\n");

    //getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);

    //scanf
    //Lights on
    printf("\n\nTo set the delay on for (in ms), type in an integer number and press return\n");
    int delay_on;
    int parsedon = scanf("%d", &delay_on);
    
    printf("You entered %d correct integer values. The value was %dms\n", parsedon, delay_on);

    //Lights on
    printf("\n\nTo set the delay off for (in ms), type in an integer number and press return\n");
    int delay_off;
    int parsedoff = scanf("%d", &delay_off);
    
    printf("You entered %d correct integer values. The value was %dms\n", parsedoff, delay_off);

    // Stop
    while (parsedon > 0) {
        led1 = 1;
        led2 = 1;
        led3 = 1;    
        wait_us(delay_on * 1000);
        led1 = 0;
        led2 = 0;
        led3 = 0;
        wait_us(delay_off * 1000);
        }
    printf("Invalid - please restart and try again\n");
    while(1);    
}