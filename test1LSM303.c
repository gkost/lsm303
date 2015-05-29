#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#define OUT_X_L_A 0x28
#define OUT_X_H_A 0x29
#define BUFFER_SIZE 256

int main()
{
    int file;
    printf("Starting the LSM303 test application\n");
    if ((file=open("/dev/i2c-1", O_RDWR)) < 0)
    {
        perror("failed to open the bus\n");
        return 1;
    }
    if (ioctl(file, I2C_SLAVE, 0x18) < 0)
    {
        perror("Failed to connect to the sensor\n");
        return 1;
    }

    char writeBuffer[1] = {OUT_X_L_A};
    if (write(file, writeBuffer, 1) != 1)
    {
        perror("Failed to reset the read address\n");
        return 1;
    }

    char readBuffer[BUFFER_SIZE];
    if (read(file, readBuffer, BUFFER_SIZE) != BUFFER_SIZE)
    {
        perror("Failed to read in the buffer\n");
        return 1;
    }
    print ("The Device OUT_X_L_A is: 0x%02x\n", readBuffer[OUT_X_L_A]);
    close (file);
    return 0;
}
