#ifndef I2C_H_
#define I2C_H_

#define BBB_I2C_0 "/dev/i2c-0"
#define BBB_I2C_1 "/dev/i2c-1"

namespace beagleBoneBlack
{
	class deviceI2C
	{
	private:
		unsigned int bus, device;
		int file;

	public:
		deviceI2C(unsigned int busNumber, unsigned int deviceID);
		virtual int open();
		virtual int write(unsigned char value);
		virtual unsigned char readRegister(unsigned int address);
		virtual unsigned char* readRegisters(unsigned int number,
											 unsigned int address=0);
		virtual int writeRegister(unsigned int address, unsigned char value);
		virtual void close();
		virtual ~deviceI2C();
	};
} // end of the name space
#endif
