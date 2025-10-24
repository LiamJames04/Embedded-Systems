#include "mbed.h"
#include <cstring>

class Rectangle {

    private:
    float length;
    float width;

    public:
    Rectangle(float w, float l){
        length = l;
        width = w;
    }

    float getarea() {
    return length * width;
    }

    float getperimeter() {

    return 2 * (length + width);
    }
};

// main() runs in its own thread in the OS
int main()
{
    printf("Program Starting................\n");

    Rectangle rect1(5.0, 3.0);

    printf("Rectangle Area: %.1f \n", rect1.getarea());
    printf("Rectangle Perimeter: %.1f \n", rect1.getperimeter());

    return 0;
}

