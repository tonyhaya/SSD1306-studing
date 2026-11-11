#include <avr/io.h>
#include "i2c.h"

/* Inicializa I2C (TWI) */
void i2c_init(void)
{
	/* SDA (PC4) e SCL (PC5) como INPUT */
	DDRC &= ((1<<PORTC4)|(1<<PORTC5));
	PORTC |= (1<<PORTC4)|(1<<PORTC5);   // pull-up

	/* Prescaler = 1 */
	TWSR = 0x00;

	/* Bit rate */
	TWBR = ((F_CPU / I2C_FREQ) - 16) / 2;

	/* Enable TWI */
	TWCR = (1<<TWEN);
}

/* START + SLA+W */
i2c_status_t i2c_start(uint8_t address)
{
	/* START */
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xF8) != 0x08)   // START transmitted
	return I2C_ERR_START;

	/* SLA+W */
	TWDR = (address<<1);      // shift automático
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xF8) != 0x18)   // SLA+W ACK
	return I2C_ERR_SLA_ACK;

	return I2C_OK;
}

/* Envia 1 byte */
i2c_status_t i2c_write(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xF8) != 0x28)   // DATA ACK
	return I2C_ERR_DATA_ACK;

	return I2C_OK;
}

/* STOP */
void i2c_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
