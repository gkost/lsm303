
#ifndef LSM303_H_
#define LSM303_H_
#include "deviceI2C.h"

#define BUFFER_SIZE 0xFF

namespace beagleBoneBlack
{
    class LSM303:protected deviceI2C
    {
    private:
        unsigned int I2CBus, I2CAddress;
        unsigned char* registers;
        short accelerationX, accelerationY, accelerationZ;
        short uniteRegisters(unsigned char msb, unsigned char lsb);

    public:
        LSM303(unsigned int I2CBus, unsigned int I2CAddress=0x18);
        virtual int readSensorData();

        virtual short getAccelX() {return accelerationX;}

        virtual ~LSM303();
    };
}



#endif // LSM303_H_
