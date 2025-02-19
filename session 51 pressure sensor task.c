
// Sensors_Prog.c

#include "StdTypes.h"
#include "LCD_Int.h"
#include "ADC_Int.h"
#include "Sensors_Cfg.h"
#include "Sensors_Int.h"



/* P*10 */
// range from 15 to 115 
u16 Pressure_Read(void)
{
	u16 adc=ADC_Read(CH_7);
	u16 press=((u32)1000*adc)/921-((u32)1000*55)/921+150;
	return press;
}
void pressur_Runnable (void)
{
	u16 x;
	u8 remainder=0;
	x=Pressure_Read();
	remainder=x%10;
	x=x/10;
	LCD_SetCursor(2,1);
	LCD_WriteNumber(x);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder);
	LCD_WriteString("        ");
}