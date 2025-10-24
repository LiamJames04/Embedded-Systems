#include "mbed.h"
#include <cstring>

class Rectangle {

    private:
    float length; // Defines legnth
    float width;  // Defines Width

    public:
    // This will initialize both the length and width
    Rectangle(float w, float l){
        length = l;
        width = w;
    }

    //This is will calculate the area through this function
    float getarea() {
    return length * width;
    }
    
    //Calculates the perimeter through this function
    float getperimeter() {

    return 2 * (length + width);
    }
};

// main() runs in its own thread in the OS
int main()
{
    printf("Program Starting................\n"); // Stages the program is starting

    Rectangle rect1(5.0, 3.0); // Create a Rectangle through this function

    //Outputs the area and perimeter of the rectangle
    printf("Rectangle Area: %.1f \n", rect1.getarea());
    printf("Rectangle Perimeter: %.1f \n", rect1.getperimeter());

    return 0;
}

