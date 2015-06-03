// This version of the program reads only accelerometer values from LSM303
// and displays data to the console
#include <iostream>
#include "LSM303.h"
#include <unistd.h>
#include <pthread.h>
#include <ctime>

using namespace beagleBoneBlack;
using namespace std;

/*LSM303 Address definitions */
#define LSM303_MAG 0x1E // this is the addres of magnetometer if SA0 is grounded
#define LSM303_ACC 0x18 // this is the addres of accelerometer if SA0 is grounded

#define SCALE 2 // This is the default scale, means +- 2g

int main()
{
    LSM303 device(1, LSM303_ACC, SCALE);

    while (1)
    {
    	device.readSensorData();
    	sleep(0.4);
    }

    return 0;
}
