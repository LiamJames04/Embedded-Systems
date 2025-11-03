#include "mbed.h"

DigitalOut led(LED1); // LED for visual feedback

#define STACK_SIZE 4 // Size of the stack (4 elements)
int stack[STACK_SIZE]; // Stack array
int top = 0; // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        printf("Error: Stack Full\n");// if stack is full, it will print this
        return;
// Handle stack full case
    }
    stack[top] = value;	// Push value onto stack and increment top
    top++;             //Increment top
}

int pop() {
    if (top <= 0) {
        printf("Error: Stack empty\n"); //If the stack is empty then this will be printed
        return -1;     
// Handle stack empty case
    }
    	top--;	// Decrement top and return the value
        return stack[top]; //returns popped value
}

void display_top() {
    if (top <= 0) {
      printf("Error: Stack empty! \n") ;
        return;
// Handle stack empty case
    }
    printf("Top value: %d\n", stack[top-1]);// Display the top value
}

int main() {
    push(10);	// Push first value
    push(20);	// Push second value

    display_top(); 	// Display top value after pushing

    pop();	// Pop the top value
    display_top(); 	// Display new top value after popping

    while (1) {
        led = !led; // Blink LED
        ThisThread::sleep_for(500ms); // Wait half a second
    }
}

