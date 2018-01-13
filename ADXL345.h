/*
 * ADXL345.h - Basic library for ADXL345 sensor
 *
 * MIT License
 *
 * Copyright (c) 2017 SGN Robotica Educacional
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LIB_ADXL345_H_
#define LIB_ADXL345_H_

/* ADXL345 communication type */
typedef enum ADXL345_COMM
{
    ADXL345_COMM_I2C,
    ADXL345_COMM_SPI,
}ADXL345_COMM_t;


class ADXL345
{
    public:

        /* Power options functions */
        void powerOn();
        void powerOff();
 
        /* Sensor core functionalities configuration functions */
        void setDataRate(float dataRate);
        float getDataRate();

        void setFullScaleRange(uint8_t fullScaleRange);
        uint8_t getFullScaleRange();

        ADXL345(ADXL345_COMM_t commType, uint8_t csPin=0);


    protected:
        /* Sensor data access */
        ADXL345_COMM_t communicationType = ADXL345_COMM_I2C;
        uint8_t _csPin;

        void writeReg(uint8_t reg_addr, uint8_t data);
        uint8_t readReg(uint8_t reg_addr);
        void readRegs(uint8_t reg_addr, uint8_t *pBuffer, uint8_t size);
};


#endif
#endif /* LIB_ADXL345_H_ */
