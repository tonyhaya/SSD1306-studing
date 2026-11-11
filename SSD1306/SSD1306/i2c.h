#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

/* Frequência do barramento */
#define I2C_FREQ 100000UL   // 100 kHz
#define F_CPU 8000000UL
/* Enum de erros do I2C */
typedef enum {
	I2C_OK = 0,
	I2C_ERR_START,
	I2C_ERR_SLA_ACK,
	I2C_ERR_DATA_ACK
} i2c_status_t;

/* API */
void i2c_init(void);
i2c_status_t i2c_start(uint8_t address);
i2c_status_t i2c_write(uint8_t data);
void i2c_stop(void);

#endif /* I2C_H_ */
