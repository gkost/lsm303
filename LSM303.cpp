#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "LSM303.h"
using namespace std;

namespace beagleBoneBlack
{
    #define SCALE 2  // accel full-scale, should be 2, 4, or 8

    /* LSM303 Address definitions */
    #define LSM303_MAG  0x1E  // assuming SA0 grounded
    #define LSM303_ACC  0x18  // assuming SA0 grounded

    #define X 0
    #define Y 1
    #define Z 2

    /* LSM303 Register definitions */
    #define CTRL_REG1_A 0x20
    #define CTRL_REG2_A 0x21
    #define CTRL_REG3_A 0x22
    #define CTRL_REG4_A 0x23
    #define CTRL_REG5_A 0x24
    #define HP_FILTER_RESET_A 0x25
    #define REFERENCE_A 0x26
    #define STATUS_REG_A 0x27
    #define OUT_X_L_A 0x28
    #define OUT_X_H_A 0x29
    #define OUT_Y_L_A 0x2A
    #define OUT_Y_H_A 0x2B
    #define OUT_Z_L_A 0x2C
    #define OUT_Z_H_A 0x2D
    #define INT1_CFG_A 0x30
    #define INT1_SOURCE_A 0x31
    #define INT1_THS_A 0x32
    #define INT1_DURATION_A 0x33
    #define CRA_REG_M 0x00
    #define CRB_REG_M 0x01
    #define MR_REG_M 0x02
    #define OUT_X_H_M 0x03
    #define OUT_X_L_M 0x04
    #define OUT_Y_H_M 0x05
    #define OUT_Y_L_M 0x06
    #define OUT_Z_H_M 0x07
    #define OUT_Z_L_M 0x08
    #define SR_REG_M 0x09
    #define IRA_REG_M 0x0A
    #define IRB_REG_M 0x0B
    #define IRC_REG_M 0x0C

    short LSM303::uniteRegisters(unsigned char msb, unsigned char lsb)
    {
        return ((short)msb<<8) | (short)lsb;
    }

    LSM303::LSM303(unsigned int I2CBus, unsigned int I2CAddress):
        deviceI2C(I2CBus, I2CAddress) // this calls the parent constructor
        {
            this->I2CAddress = I2CAddress;
            this->I2CBus = I2CBus;
            this->accelerationX = 0;
            this->registers = NULL;
            this->writeRegister(CTRL_REG1_A, 0x27); // 0x27 - normal power mode, all axes on
        }

    void LSM303::readSensorData()
    {
        this->registers = this->readRegisters(BUFFER_SIZE, 0x00);
        //this->accelerationX = this->combineRegisters
    }

    LSM303::~LSM303()
    {

    }
}

