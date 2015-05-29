class deviceI2C
{
private:
    unsigned int busNumber, deviceID;
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
