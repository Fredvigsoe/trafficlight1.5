#ifndef PORTS_H
#define PORTS_H

// Register-adresser for DDR (Data Direction Register) og PORT (Data Register) for Port D
#define DDRD   (*(volatile uint8_t *)0x2A)  // Data Direction Register for Port D (D0-D7)
#define PORTD  (*(volatile uint8_t *)0x2B)  // Data Register for Port D (D0-D7)
#define PIND   (*(volatile uint8_t *)0x29)  // Input Pins for Port D (D0-D7)

// Register-adresser for DDR (Data Direction Register) og PORT (Data Register) for Port B
#define DDRB   (*(volatile uint8_t *)0x24)  // Data Direction Register for Port B (D8-D13)
#define PORTB  (*(volatile uint8_t *)0x25)  // Data Register for Port B (D8-D13)
#define PINB   (*(volatile uint8_t *)0x23)  // Input Pins for Port B (D8-D13)

// Pins for trafiklys (NS og EW lysdioder)
#define NS_GREEN   (1 << 2)  // PD2 - Grøn NS (D2)
#define NS_YELLOW  (1 << 3)  // PD3 - Gul NS (D3)
#define NS_RED     (1 << 4)  // PD4 - Rød NS (D4)

#define EW_GREEN   (1 << 5)  // PD5 - Grøn EW (D5)
#define EW_YELLOW  (1 << 6)  // PD6 - Gul EW (D6)
#define EW_RED     (1 << 7)  // PD7 - Rød EW (D7)

// Pins for fodgængere (NS og EW)
#define NS_GREEN_FOOT (1 << 0)  // PB0 - Grøn fodgænger NS (D8)
#define NS_RED_FOOT   (1 << 1)  // PB1 - Rød fodgænger NS (D9)
#define EW_GREEN_FOOT (1 << 2)  // PB2 - Grøn fodgænger EW (D10)
#define EW_RED_FOOT   (1 << 3)  // PB3 - Rød fodgænger EW (D11)

// Fodgængerknapper
#define BUTTON_NS (1 << 4)  // Knap for NS (PB4 - D12)
#define BUTTON_EW (1 << 5)  // Knap for EW (PB5 - D13)

#endif
