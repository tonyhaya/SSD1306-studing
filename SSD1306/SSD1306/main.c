
#include <avr/io.h>
#include <util/delay.h>

#include "i2c.h"
#include "ssd1306.h"

int main(void)
{
	i2c_init();
	ssd1306_init();
	//ssd1306_clear();   // se isso funcionar, o display está OK
    //ssd1306_set_cursor(0, 0);     // página 0, coluna 0
    //ssd1306_print("ABC DEF");
	//render();
	while (1)
	{
		// nada
	}
}
