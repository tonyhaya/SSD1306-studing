#include <util/delay.h>
#include "ssd1306.h"
#include "i2c.h"




/* Inicialização mínima funcional */
void ssd1306_init(void)
{
	_delay_ms(100); // tempo obrigatório após power-on
	GLCD_SendCommand(__GLCD_Command_Display_Off);				//0xAE
	
	GLCD_SendCommand(__GLCD_Command_Display_Clock_Div_Ratio_Set);		//0xD5
	GLCD_SendCommand(0xF0);							//Suggest ratio
	
	GLCD_SendCommand(__GLCD_Command_Multiplex_Radio_Set);			//0xA8
	GLCD_SendCommand(__GLCD_Screen_Height - 1);
	
	GLCD_SendCommand(__GLCD_Command_Display_Offset_Set);			//0xD3
	GLCD_SendCommand(0x00);							//No offset

	GLCD_SendCommand(__GLCD_Command_Charge_Pump_Set);			//0x8D
	GLCD_SendCommand(0x14);							//Enable charge pump

	GLCD_SendCommand(__GLCD_Command_Display_Start_Line_Set | 0x00);		//0x40 | Start line
	
	GLCD_SendCommand(__GLCD_Command_Memory_Addressing_Set);			//0x20
	GLCD_SendCommand(0x00);							//Horizontal Addressing - Operate like KS0108
	
	GLCD_SendCommand(__GLCD_Command_Segment_Remap_Set | 0x01);		//0xA0 - Left towards Right

	GLCD_SendCommand(__GLCD_Command_Com_Output_Scan_Dec);			//0xC8 - Up towards Down

	GLCD_SendCommand(__GLCD_Command_Com_Pins_Set);				//0xDA
	
	#if (GLCD_Size == GLCD_128_64)
	GLCD_SendCommand(0x12);						//Sequential COM pin configuration
	#elif (GLCD_Size == GLCD_128_32)
	GLCD_SendCommand(0x02);						//Alternative COM pin configuration
	#elif (GLCD_Size == GLCD_96_16)
	GLCD_SendCommand(0x02);						//Alternative COM pin configuration
	#endif
	
	GLCD_SendCommand(__GLCD_Command_Constrast_Set);				//0x81
	GLCD_SendCommand(0xFF);

	GLCD_SendCommand(__GLCD_Command_Precharge_Period_Set);			//0xD9
	GLCD_SendCommand(0xF1);

	GLCD_SendCommand(__GLCD_Command_VCOMH_Deselect_Level_Set);		//0xDB
	GLCD_SendCommand(0x20);

	GLCD_SendCommand(__GLCD_Command_Display_All_On_Resume);			//0xA4
	GLCD_SendCommand(__GLCD_Command_Display_Normal);			//0xA6
	GLCD_SendCommand(__GLCD_Command_Scroll_Deactivate);			//0x2E
	GLCD_SendCommand(__GLCD_Command_Display_On);
	GLCD_SendCommand(0xA7);
}

void GLCD_SendCommand(uint8_t Command){
	
	
}

