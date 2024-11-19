#ifndef LIGHTS_H
#define LIGHTS_H

#include <stdint.h>

// Delay funktion
void delay_ms(uint16_t ms);

// Trafiklys kontrol
void NS_TurnRed();
void NS_TurnYellow();
void NS_TurnGreen();
void NS_TurnOff();
void NS_PrepareToSwitch();

void EW_TurnRed();
void EW_TurnYellow();
void EW_TurnGreen();
void EW_TurnOff();
void EW_PrepareToSwitch();

// Fodgængerlys
void NS_FootGreenOn();
void NS_FootGreenOff();
void NS_FootRedOn();
void NS_FootRedOff();

void EW_FootGreenOn();
void EW_FootGreenOff();
void EW_FootRedOn();
void EW_FootRedOff();

// Fodgænger og knapper
void handle_pedestrian_button(uint8_t button_pin, uint8_t button_mask, int direction);
void NS_PedestrianCrossing();
void EW_PedestrianCrossing();
void manage_traffic_lights();

#endif