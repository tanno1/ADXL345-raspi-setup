//Noah tanner
//Accelerometer Test Script
//October 2022

//Include tags
#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>

//Define device ID
#define DEVICE_ID 0x53

//Define REGISTERS
#define POWER_CTRL 0x2D
#define DATA_X_LOW 0x32
#define DATA_X_HIGH 0x33
#define DATA_Y_LOW 0x34
#define DATA_Y_HIGH 0x35
#define DATA_Z_LOW 0x36
#define DATA_Z_HIGH 0x37

//initialize the I2C communication
int main (int argc, char **argv)
{
	//setup I2C communication
	int fd = wiringPiI2CSetup(DEVICE_ID);
	if (fd == -1)	{
		std::cout << "Failed to init I2C communication.\n";
		return -1;
	}
	std::cout << "I2C communication successfully setup.\n";
	
	//Switch into measurement mode, 4th bit of 8-bit register
	wiringPiI2CWriteReg8(fd, POWER_CTRL, 0b00001000);
	
	//Reading data from register
	while (1) {
		int dataX = wiringPiI2CReadReg16(fd, DATA_X_LOW);
		dataX = -(~(int16_t)dataX + 1);
		
		int dataY = wiringPiI2CReadReg16(fd, DATA_Y_LOW);
		dataY = -(~(int16_t)dataY + 1);
		
		int dataZ = wiringPiI2CReadReg16(fd, DATA_Z_LOW);
		dataZ = -(~(int16_t)dataZ + 1);
		
		std::cout << "X: " << dataX << ", Y: " << dataY << ", z: " << dataZ << "\n";
		
std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
return 0;
}
	

