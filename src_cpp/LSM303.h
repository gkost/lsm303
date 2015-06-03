
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
        short uniteRegisters(unsigned char msb, unsigned char lsb);
        double getHeading(int *magValue);
        void getMag(int *rawValues);

    public:
        LSM303(unsigned int I2CBus, unsigned int I2CAddress=0x18, char scale=0x02);
        virtual void readSensorData();



        virtual ~LSM303();
    };
}



#endif // LSM303_H_
