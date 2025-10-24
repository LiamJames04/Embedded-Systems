#include "mbed.h"
AnalogIn tempSensor(A0); //Temperature sensor input
PwmOut led(PA_5); // PWM output for LED



// main() runs in its own thread in the OS
int main()
{
    const float pollingInterval = 0.1f; // 100ms polling interval
    printf("Program is starting........\n");
    
    float tempC = 0.0f;//This is the variable to store the temperature value
    float brightness = 0.0f; //This is the value to the brightness value
    
    while (true) {
        //Step 1 Read analog value from temperature sensor
        //Read Analog vlaue (0.0-1.0)
        float Valueanalog = tempSensor.read();

        //Steo 2 Convert analog value tp temperature on °C
        // Convert to temperature (0°C - 100°C)
        tempC = Valueanalog * 100.0f;
        

        // Step 3: This step will adjust the brightness of the LED depending on the tempertature valu
        if (tempC < 20.0f){
            brightness = 0.0f; // The led will remian off if it is lower than °C
        }
        else if (tempC>=20.0f && tempC<=40.0f){
            //This will scale the brightness of the LED between the temperature values of 20°C and 40°C
            brightness = (tempC - 20.0f) / 20.0f;
        }
        else {
            //If the temperature value is over 40°C then the LED will remain on at all times
            brightness = 1.0f;
        }

        //This will write the brightness value of the LED between 0.0 and 1.0 dependent on the temperature value
        led.write(brightness);

        //This will print both value of the temperature and brightness of the LED at all times
        printf("Temperature: %.2f | Brightness: %.2f\n", tempC, brightness);
   

        //Step 5: this is a delay so that the code will re-run every 100ms
        ThisThread::sleep_for(100ms);
    }
}

