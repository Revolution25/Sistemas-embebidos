
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
    TRISB = 1;  // Configuro PORTB como entrada
    TRISD=0;    //Configuro PORTD como salida
    ANSEL=0;    //Aseguro que PORTB sea entrada digital
    ANSELH=0;   //Aseguro que PORTB sea entrada digital
    __delay_ms(32); //Retardo para poder ver el primer bit
    PORTB=0;
    
    
    TRISCbits.TRISC6 = 0;
    TXSTAbits.SYNC = 0;
    TXSTAbits.TX9 = 0;
    TXSTAbits.BRGH = 0;
    BAUDCTLbits.BRG16=0;
    SPBRG = 25;
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1;
    
   
    
    if (PORTB>=128){
       while(1){
    switch (PORTB){
        case 0: TXREG =0;
            PORTD=63;
        break;
        case 1: TXREG =10;
            PORTD=6;
        break;
        case 2: TXREG =20;
            PORTD=91;
        break;
        case 3: TXREG =30;
            PORTD=79;
        break;
        case 4: TXREG =40;
            PORTD=102;
        break;
        case 5: TXREG =50;
            PORTD=109;
        break;
        case 6: TXREG =60;
            PORTD=125;
        break;
        case 7: TXREG =70;
            PORTD=7;
        break;
        case 8: TXREG =80;
            PORTD=127;
        break;
        case 9: TXREG =90;
            PORTD=111;
        break;
    }
     }
    }
     
    
}