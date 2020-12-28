#include "compiler_defs.h"
#include "C8051F380_defs.h"
#include "lcd_4bit.h"
#include "delay.h"

void Init_Device(void);

void servo(unsigned int Width)  //P0.0
{
	if(Width>2300) Width=2300;
	if(Width<700) Width=700;
	Width=-4*Width;
	
		PCA0CPL0= Width;
		PCA0CPH0= Width>>8;	
}

void main(void)
{
	int t1=0;
	int t2=0;

	Init_Device();
	lcd_begin();
	lcd_println("  Servo  ");

	while(1){	
		    lcd_print_Position(2,0," 0 degrees   ");
				servo(700);
				delay_ms(2000);
		    lcd_print_Position(2,0," 90 degrees   ");
				servo(1500);
				delay_ms(2000);
		    lcd_print_Position(2,0," 180 degrees   ");
				servo(2300);
				delay_ms(2000);
	}
}