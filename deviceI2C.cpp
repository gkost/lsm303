#include <iostream>
#include <fcntl.h>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <deviceI2C.h>

using namespace beagleBoneBlack
{
    // Constructor of the class deviceI2C
    deviceI2C::deviceI2C(unsigned int busNumber, unsigned int deviceID)
    {
        this->file = -1;
        this->bus = busNumber;
        this->device = deviceID;
        this->open();
    }

    // Open a connection to the device
    int deviceI2C::open()
    {
        string name;
        if (this->bus == 0) name = BBB_I2C_0;
        else name = BBB_I2C_1;

        if ((this->file=::open(name.c_str(), O_RDWR)) < 0)
        {
            perror("Failed to open the I2C bus!\n");
            return 1;
        }
        if (ioctl(this->file, I2C_SLAVE, this->device) < 0)
        {
            perror("Failed to connect to the I2C device!\n");
            return 1;
        }
        return 0;
    }

    // Writes a single byte to a given register
    int deviceI2C::writeRegister(unsigned int address, unsigned char value)
    {
        unsigned char buffer[2];
        buffer[0] = address;
        buffer[1] = value;
        if (::write(this->file, buffer, 2) != 2)
        {
            perror("Failed writing to the device\n");
            return 1;
        }
        return 0;
    }

    // Writes a single value to the device
    int deviceI2C::write(unsigned char value)
    {
        unsigned char buffer[1];
        buffer[0] = value;
        if (::write(this->file, buffer, 1) != 1)
        {
            perror("Failed to write to the device\n");
            return 1;
        }
    }

    // Reads a single register value from the address on the device
    unsigned char deviceI2C::readRegister(unsigned int address)
    {
        this->write(address);
        unsigned char buff[1];
        if (::read(this->file, buff, 1) != 1)
        {
            perror("Failed to read from the device!\n");
            return 1;
        }
        return buff[0];
    }

    // Reads a couple of registers at the same time
    unsigned char* deviceI2C::readRegisters(unsigned int number, unsigned int address)
    {
        this->write(address);
        unsigned char* data = new unsigned char[number];
        if (::read(this->file, data, number) != (int)number)
        {
            perror("Failed to read the whole buffer!\n");
            return NULL;
        }
        return data;
    }

    void deviceI2C::close()
    {
        ::close(this->file);
        this->file = -1;
    }

    deviceI2C::~deviceI2C()
    {
        if (file != -1) this->close();
    }
} // end of the name space
