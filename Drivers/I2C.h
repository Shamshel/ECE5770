//I2C.h

#ifndef I2C_H
#define I2C_H

#define I2CMSA		0x000
#define I2CMCS		0x004
#define I2CDR			0x008
#define I2CMTPR		0x00C
#define I2CMIMR		0x010
#define I2CMRIS		0x014
#define I2CMMIS		0x018
#define I2CMICR		0x01C
#define I2CMCR		0x020
#define I2CSOAR		0x800
#define	I2CSCSR		0x804
#define I2CSDR		0x808
#define I2CSIMR		0x80C
#define I2CSRIS		0x810
#define I2CSMIS		0x814
#define I2CSICR		0x818

#define I2C0 ((unsigned char*)0x40020000)
#define I2C1 ((unsigned char*)0x40021000)

void i2c_config(unsigned char* i2c, unsigned int MTPR);
void i2c_tx(unsigned char* i2c, unsigned char slaveAddr, unsigned char* data, unsigned char len);
void i2c_rx(unsigned char* i2c, unsigned char slaveAddr, unsigned char* data, unsigned char len);

#endif
