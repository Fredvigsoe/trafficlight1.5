# Arduino Traffic Light Project med Fodgængerovergang

Dette projekt implementerer et avanceret trafiklys på en Arduino (ATmega328P) med trafikstyring og fodgængerovergange. Systemet styrer lysdioder for to retninger (Nord-Syd og Øst-Vest) med fuld signalregulering og brugerinteraktion via fodgængerknapper.

## Hardware Konfiguration

### Trafiklys
- **Nord-Syd lysdioder**:
  - Rød (PD4)
  - Gul (PD3)
  - Grøn (PD2)

- **Øst-Vest lysdioder**:
  - Rød (PD7)
  - Gul (PD6)
  - Grøn (PD5)

### Fodgængerbelysning
- **Nord-Syd fodgænger**:
  - Rød (PB1)
  - Grøn (PB0)

- **Øst-Vest fodgænger**:
  - Rød (PB3)
  - Grøn (PB2)

### Fodgængerknapper
- Nord-Syd knap (PB4)
- Øst-Vest knap (PB5)

## Funktionalitet
- Trafiksignaler skifter mellem retningerne
- Fodgængerknapper aktiverer kun overgang, når tilsvarende trafiksignal er grønt
- Sikrer sikker krydsning ved at synkronisere fodgængeranlæg med trafiksignaler

## Kompilering og Upload Instruktioner

### 1. Find USB-port
```bash
ls /dev/tty*
```

### 2. Kompiler koden
```bash
avr-gcc -mmcu=atmega328p -Os -o trafficlight.elf lights.c main.c
```

### 3. Konverter til HEX
```bash
avr-objcopy -O ihex trafficlight.elf trafficlight.hex
```

### 4. Upload til Arduino
```bash
avrdude -p m328p -c arduino -P /dev/tty.DINUSBPORT -U flash:w:trafficlight.hex:i
```

## Sikkerhedsfunktioner
- Forhindrer samtidige grønne signaler i modsat retning
- Implementerer ventetid mellem retningsskift
- Beskytter fodgængere ved kun at tillade krydsning ved grønt trafiksignal



https://github.com/user-attachments/assets/bca306aa-aa10-446e-88ae-674f19c3cc96




  
