
#pragma config FOSC = XT      // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

#include <stdlib.h>
#include <xc.h>
#include <PIC16F887.h>
#define _XTAL_FREQ 4000000      // Frecuencia del cristal a utilizar.

int main() {
    TRISD=0;    //Configuro PORTD como salida
    ANSEL=0;    //Aseguro que PORTB sea entrada digital
    ANSELH=0;   //Aseguro que PORTB sea entrada digital
    __delay_ms(32); //Retardo para poder ver el primer bit
    
    TRISCbits.TRISC7 = 1; //rx como entrada
    TXSTAbits.SYNC = 0; //uart
    RCSTAbits.RX9 = 0;  //8 bits
    TXSTAbits.BRGH = 0;  //baja velocidad
    BAUDCTLbits.BRG16=0;
    SPBRG = 25;
    RCSTAbits.SPEN = 1; //Euart on
    RCSTAbits.CREN = 1; //rx on
    
    while(1){
    switch (RCREG){
        case 0:
            PORTD=63;
            
        break;
        case 10: 
            PORTD=6;
        break;
        case 20: 
            PORTD=91;
        break;
        case 30: 
            PORTD=79;
        break;
        case 40: 
            PORTD=102;
        break;
        case 50: 
            PORTD=109;
        break;
        case 60: 
            PORTD=125;
        break;
        case 70: 
            PORTD=7;
        break;
        case 80: 
            PORTD=127;
        break;
        case 90: 
            PORTD=111;
        break;
        
    }
    }
    }