#include <stdint.h>
#include <avr/io.h>
#include "lights.h"
#include "ports.h"

// Delay funktion fra trafiklys 1.0
void delay_ms(uint16_t ms) {
    while (ms--) {
        volatile uint16_t i;
        for (i = 0; i < 1600; i++) {
            __asm__ __volatile__("nop");
        }
    }
}

// Bit manipulation til tjek af knappen
#define bit_is_clear(reg, bit) (!(reg & bit))

// Trafiklys for Nord-Syd
void NS_TurnGreen()    { PORTD |= NS_GREEN; }
void NS_TurnYellow()   { PORTD |= NS_YELLOW; }
void NS_TurnRed()      { PORTD |= NS_RED; }
void NS_TurnOff()      { PORTD &= ~(NS_GREEN | NS_YELLOW | NS_RED); }

// Trafiklys for Øst-Vest
void EW_TurnGreen()    { PORTD |= EW_GREEN; }
void EW_TurnYellow()   { PORTD |= EW_YELLOW; }
void EW_TurnRed()      { PORTD |= EW_RED; }
void EW_TurnOff()      { PORTD &= ~(EW_GREEN | EW_YELLOW | EW_RED); }

// Fodgænger Nord-Syd
void NS_FootGreenOn()  { PORTB |= NS_GREEN_FOOT; }
void NS_FootGreenOff() { PORTB &= ~NS_GREEN_FOOT; }
void NS_FootRedOn()    { PORTB |= NS_RED_FOOT; }
void NS_FootRedOff()   { PORTB &= ~NS_RED_FOOT; }

// Fodgænger Øst-Vest
void EW_FootGreenOn()  { PORTB |= EW_GREEN_FOOT; }
void EW_FootGreenOff() { PORTB &= ~EW_GREEN_FOOT; }
void EW_FootRedOn()    { PORTB |= EW_RED_FOOT; }
void EW_FootRedOff()   { PORTB &= ~EW_RED_FOOT; }

// Global variables for button state
volatile uint8_t ns_button_pressed = 0;
volatile uint8_t ew_button_pressed = 0;

// Fodgænger knap funktion
void handle_pedestrian_button(uint8_t button_pin, uint8_t button_mask, int direction) {
    if (bit_is_clear(button_pin, button_mask)) {
        if (direction == 0 && !ns_button_pressed) {
            ns_button_pressed = 1;
        } else if (direction == 1 && !ew_button_pressed) {
            ew_button_pressed = 1;
        }
    }
}

// Klar til at skifte Nord-Syd
void NS_PrepareToSwitch() {
    NS_TurnYellow();
    EW_TurnRed();
    delay_ms(1000);
}
// Klar til at skifte Øst-Vest
void EW_PrepareToSwitch() {
    EW_TurnYellow();
    NS_TurnRed();
    delay_ms(1000);
}

// Fodgænger Nord-Syd
void NS_PedestrianCrossing() {
    NS_FootRedOff();
    NS_FootGreenOn();
    delay_ms(3000);
    NS_FootGreenOff();
    NS_FootRedOn();
    ns_button_pressed = 0;
}
// Fodgænger Øst-Vest
void EW_PedestrianCrossing() {
    EW_FootRedOff();
    EW_FootGreenOn();
    delay_ms(3000);
    EW_FootGreenOff();
    EW_FootRedOn();
    ew_button_pressed = 0;
}

// Kontrol af trafiklys
void manage_traffic_lights() {
    // Start: alt rødt
    NS_TurnRed();
    EW_TurnRed();
    NS_FootRedOn();
    EW_FootRedOn();
    delay_ms(2000);

    // Øst-Vest rød og gul
    EW_TurnYellow();
    delay_ms(1000);

    // Øst-Vest sluk rød og gul, og tænd grøn
    EW_TurnOff();
    EW_TurnGreen();
    
    // Tillad kun at blive grønt hos øst-vest fodgænger hvis der er grønt for trafikken
    if (ew_button_pressed) {
        EW_PedestrianCrossing();
    }
    
    delay_ms(ew_button_pressed ? 1000 : 2000);
    
    // Øst-vest sluk grøn, tænd gul
    EW_TurnOff();
    EW_TurnYellow();
    delay_ms(1000);

    // Øst-vest sluk gul, tænd rød
    EW_TurnOff();
    EW_TurnRed();
    delay_ms(2000);

    // Samme for Nord-Syd //
    NS_TurnYellow();
    delay_ms(1000);


    NS_TurnOff();
    NS_TurnGreen();
    
   
    if (ns_button_pressed) {
        NS_PedestrianCrossing();
    }
    
    delay_ms(ns_button_pressed ? 1000 : 2000);

   
    NS_TurnOff();
    NS_TurnYellow();
    delay_ms(1000);

    
    NS_TurnOff();
    NS_TurnRed();
    delay_ms(2000);
}