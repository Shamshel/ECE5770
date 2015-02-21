//I2C.c

#include "I2C.h"
#include "regop.h"
#include "SYSCTL.h"

void i2c_config(unsigned char* i2c, unsigned int MTPR)
{	
	//enable master
	writeReg(i2c, I2CMCR, 0x20);
	
	//set clock speed
	writeReg(i2c, I2CMTPR, MTPR);
	
}

//status fields on page 530
void i2c_tx(unsigned char* i2c, unsigned char slaveAddr, unsigned char* data, unsigned char len)
{
	int i = 0;
	
	//put slave address, clear rx/tx bit
	writeReg(i2c, I2CMSA, slaveAddr<<1);
	
	writeReg(i2c, I2CDR, data[0]);
	
	//begin continuous transmit
	if(len > 1)
	{
		writeReg(i2c, I2CMCS, 0x03);
	
		for(i = 1; i < (len-1); i++)
		{	
			//poll busy bit
			while(readReg(i2c, I2CMCS)&0x01);
		
			writeReg(i2c, I2CDR, data[i]);
		
			writeReg(i2c, I2CMCS, 0x01);
		
		}
	
		//transmit last byte
		writeReg(i2c, I2CDR, data[len-1]);
		
		writeReg(i2c, I2CMCS, 0x7);
		
		//poll busy bit
		while(readReg(i2c, I2CMCS)&0x01);
		
	}
	
	//transmit single byte
	else
	{
		writeReg(i2c, I2CMCS, 0x07);
		
		while(readReg(i2c, I2CMCS)&0x01);
		
	}
	
}

void i2c_rx(unsigned char* i2c, unsigned char slaveAddr, unsigned char* data, unsigned char len)
{
	int i = 0;
	
	writeReg(i2c, I2CMSA, (slaveAddr<<1) + 1);
	
	//begin continuous recieve
	if(len > 1)
	{
		writeReg(i2c, I2CMCS, 0x03);
	
		for(i = 0; i < (len-1); i++)
		{	
			//poll busy bit
			while(readReg(i2c, I2CMCS)&0x01);
		
			data[i] = readReg(i2c, I2CDR);
		
			writeReg(i2c, I2CMCS, 0x01);
		
		}
	
		//recieve last byte		
		writeReg(i2c, I2CMCS, 0x7);
		
		while(readReg(i2c, I2CMCS)&0x01);
		
		data[len-1] = readReg(i2c, I2CDR);
		
	}
	
	//recieve single byte
	else
	{
		writeReg(i2c, I2CMCS, 0x07);
		
		while(readReg(i2c, I2CMCS)&0x01);
		
		data[0] = readReg(i2c, I2CDR);
		
	}
	
}
