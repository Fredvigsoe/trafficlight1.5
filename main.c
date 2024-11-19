#include "lights.h"
#include "ports.h"
#include <stdint.h>

int main(void) {
    // Initialize ports
    DDRD |= (NS_RED | NS_YELLOW | NS_GREEN | 
             EW_RED | EW_YELLOW | EW_GREEN);
    
    DDRB |= (NS_GREEN_FOOT | NS_RED_FOOT | 
             EW_GREEN_FOOT | EW_RED_FOOT);
    
    // Set button pins as inputs
    DDRB &= ~(BUTTON_NS | BUTTON_EW);
    
    // Enable pull-up resistors for buttons
    PORTB |= (BUTTON_NS | BUTTON_EW);
    
    // Initial state: All red
    NS_TurnRed();
    EW_TurnRed();
    NS_FootRedOn();
    EW_FootRedOn();

    while (1) {
        manage_traffic_lights();
        
        // Check pedestrian buttons
        handle_pedestrian_button(PINB, BUTTON_NS, 0);
        handle_pedestrian_button(PINB, BUTTON_EW, 1);
    }

    return 0;
}