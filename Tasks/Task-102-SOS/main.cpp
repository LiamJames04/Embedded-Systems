// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;
LCD_16X2_DISPLAY lcd;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        //3 Dots
        //On for 500ms

        lcd.cls();

        lcd.printf("3 DOTS");
        lcd.locate(1, 0);   //Row 1, Col 0
        lcd.printf(". . .");

        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);


        //3 Dashes
        //Off for 500ms

        lcd.cls();

        lcd.printf("3 DASHES");
        lcd.locate(1, 0);   //Row 1, Col 0
        lcd.printf("- - -");

        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 450);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 450);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS * 450);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        //3 Dots
        //On for 500ms

        lcd.cls();

        lcd.printf("3 DOTS");
        lcd.locate(1, 0);   //Row 1, Col 0
        lcd.printf(". . .");

        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        buzz.rest();
        wait_us(WAIT_TIME_MS * 500);

        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1500);

    }
}