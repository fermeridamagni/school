/**
 * @file main.c
 * @author ferme
 * @date 2025-09-24
 * @brief Main function
 * @details Get the analogic value from the ADC in the PIC16F887 and control
 * PORTB LEDs based on the ADC value.
 */

#include <pic16f887.h> // Include the specific header for PIC16F887
#include <xc.h>

// Define the system frequency for delay functions
#define _XTAL_FREQ 8000000 // 8MHz internal oscillator

// Configuration bits
#pragma config FOSC = INTRC_NOCLKOUT // Internal RC oscillator, no CLKOUT
#pragma config WDTE = OFF            // Watchdog Timer disabled
#pragma config PWRTE = ON            // Power-up Timer enabled
#pragma config MCLRE = ON            // MCLR pin function enabled
#pragma config CP = OFF              // Code protection disabled
#pragma config CPD = OFF             // Data code protection disabled
#pragma config BOREN = ON            // Brown-out Reset enabled
#pragma config IESO = ON             // Internal/External Switchover enabled
#pragma config FCMEN = ON            // Fail-Safe Clock Monitor enabled
#pragma config LVP = OFF             // Low Voltage Programming disabled
#pragma config DEBUG = OFF           // In-Circuit Debugger disabled
#pragma config BOR4V = BOR40V        // Brown-out Reset 4.0V
#pragma config WRT = OFF // Flash Program Memory Write Enable bits off

void main() {
  // Configure analog input pin
  TRISAbits.TRISA0 = 1; // Set RA0 (AN0) as input
  ANSEL = 0x01;         // Enable analog input on AN0 (bit 0), others digital

  // Initialize the ADC
  ADCON0 = 0x41; // Enable ADC (ADON=1), select channel AN0 (CHS2:0=000)
  ADCON1 = 0x80; // Right justified, VDD/VSS references

  // Output pins
  TRISBbits.TRISB0 = 0; // Set RB0 as output
  TRISBbits.TRISB1 = 0; // Set RB1 as output
  TRISBbits.TRISB2 = 0; // Set RB2 as output
  TRISBbits.TRISB3 = 0; // Set RB3 as output
  TRISBbits.TRISB4 = 0; // Set RB4 as output
  TRISBbits.TRISB5 = 0; // Set RB5 as output
  TRISBbits.TRISB6 = 0; // Set RB6 as output
  TRISBbits.TRISB7 = 0; // Set RB7 as output

  while (1) {
    // Allow acquisition time
    __delay_us(20); // Acquisition time delay (minimum 19.72us for 10-bit)

    // Start ADC conversion
    GO_nDONE = 1; // Start conversion (alternative: ADCON0bits.GO_DONE = 1)
    while (GO_nDONE)
      ; // Wait for conversion to complete

    // Read 10-bit ADC result (0-1023) - right justified
    int adc_value = (ADRESH << 8) | ADRESL;

    if (adc_value <= 128) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 0; // Set RB1 low
      PORTBbits.RB2 = 0; // Set RB2 low
      PORTBbits.RB3 = 0; // Set RB3 low
      PORTBbits.RB4 = 0; // Set RB4 low
      PORTBbits.RB5 = 0; // Set RB5 low
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 256) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 0; // Set RB2 low
      PORTBbits.RB3 = 0; // Set RB3 low
      PORTBbits.RB4 = 0; // Set RB4 low
      PORTBbits.RB5 = 0; // Set RB5 low
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 384) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 0; // Set RB3 low
      PORTBbits.RB4 = 0; // Set RB4 low
      PORTBbits.RB5 = 0; // Set RB5 low
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 512) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 1; // Set RB3 high
      PORTBbits.RB4 = 0; // Set RB4 low
      PORTBbits.RB5 = 0; // Set RB5 low
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 640) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 1; // Set RB3 high
      PORTBbits.RB4 = 1; // Set RB4 high
      PORTBbits.RB5 = 0; // Set RB5 low
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 768) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 1; // Set RB3 high
      PORTBbits.RB4 = 1; // Set RB4 high
      PORTBbits.RB5 = 1; // Set RB5 high
      PORTBbits.RB6 = 0; // Set RB6 low
      PORTBbits.RB7 = 0; // Set RB7 low
    } else if (adc_value <= 896) {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 1; // Set RB3 high
      PORTBbits.RB4 = 1; // Set RB4 high
      PORTBbits.RB5 = 1; // Set RB5 high
      PORTBbits.RB6 = 1; // Set RB6 high
      PORTBbits.RB7 = 0; // Set RB7 low
    } else {
      PORTBbits.RB0 = 1; // Set RB0 high
      PORTBbits.RB1 = 1; // Set RB1 high
      PORTBbits.RB2 = 1; // Set RB2 high
      PORTBbits.RB3 = 1; // Set RB3 high
      PORTBbits.RB4 = 1; // Set RB4 high
      PORTBbits.RB5 = 1; // Set RB5 high
      PORTBbits.RB6 = 1; // Set RB6 high
      PORTBbits.RB7 = 1; // Set RB7 high
    }

    // Small delay to prevent excessive ADC reading rate
    __delay_ms(10);
  }
}
