#ifndef SSD1306_H_
#define SSD1306_H_

#include <stdint.h>

#define SSD1306_ADDR 0x3C

#define __GLCD_Screen_Width 64
#define  __GLCD_Screen_Height 128
#define __GLCD_Screen_Lines	(__GLCD_Screen_Height /8)
//Fundamental Command Table
#define __GLCD_Command_Display_On				0xAF
#define __GLCD_Command_Display_Off				0xAE
#define __GLCD_Command_Constrast_Set				0x81
#define __GLCD_Command_Display_All_On_Resume			0xA4
#define __GLCD_Command_Display_All_On				0xA5
#define __GLCD_Command_Display_Normal				0xA6
#define __GLCD_Command_Display_Inverse				0xA7

//Scrolling Command Tab
#define __GLCD_Command_Scroll_Activate				0x2F
#define __GLCD_Command_Scroll_Deactivate			0x2E
#define __GLCD_Command_Scroll_Left				0x27
#define __GLCD_Command_Scroll_Right				0x26
#define __GLCD_Command_Scroll_Vertical_Left			0x2A
#define __GLCD_Commad_Scroll_Vertical_Right			0x29
#define __GLCD_Command_Scroll_Vertical_Area_Set			0xA3

//Addressing Setting Command Table
#define __GLCD_Command_Page_Addressing_Column_Lower_Set		0x00
#define __GLCD_Command_Page_Addressing_Column_Higher_Set	0x10
#define __GLCD_Command_Page_Addressing_Page_Start_Set		0xB0
#define __GLCD_Command_Page_Address_Set				0x22
#define __GLCD_Command_Memory_Addressing_Set			0x20
#define __GLCD_Command_Column_Address_Set			0x21

//Hardware Configuration
#define __GLCD_Command_Display_Start_Line_Set			0x40
#define __GLCD_Command_Display_Offset_Set			0xD3
#define __GLCD_Command_Segment_Remap_Set			0xA0
#define __GLCD_Command_Multiplex_Radio_Set			0xA8
#define __GLCD_Command_Com_Output_Scan_Inc			0xC0
#define __GLCD_Command_Com_Output_Scan_Dec			0xC8
#define __GLCD_Command_Com_Pins_Set				0xDA

//Timing and Driving Scheme Setting Command Table
#define __GLCD_Command_Display_Clock_Div_Ratio_Set		0xD5
#define __GLCD_Command_Display_Oscillator_Frequency_Set		0xD5
#define __GLCD_Command_Precharge_Period_Set			0xD9
#define __GLCD_Command_VCOMH_Deselect_Level_Set			0xDB
#define __GLCD_Command_Nop					0xE3

//Charge Pump Command Table
#define __GLCD_Command_Charge_Pump_Set				0x8D

void ssd1306_init(void);
//void GLCD_Send(const uint8_t Control, uint8_t *Data, const uint8_t Length);
void GLCD_SendCommand(uint8_t Command);
//void render(void);
#endif
