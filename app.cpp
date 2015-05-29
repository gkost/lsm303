#include <iostream>
#include "LSM303.h"
#include <unistd.h>
#include <pthread.h>

using namespace beagleBoneBlack;
using namespace std;

int main()
{
    LSM303 device(1, 0x18);
    device.readSensorData();

    return 0;
}
