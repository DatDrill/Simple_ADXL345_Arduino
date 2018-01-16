# ADXL345 - An Arduino easy to use library

This library was designed to be used with the Arduino framework and the ADXL345 accelerometer with SPI or I2C communication, focusing an easy to use interface with the library.

#### Changelog
* __1.0__ - Initial release(15 Jan 2018)
    * Operates with SPI or I2C communication   
    * 3 axis acceleration reading
    * Full scale range and Sampling Frequency configuration
    * Power on/off for energy management

## Setup

You can install this library by following the "[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)" tutorial

Don't forget to check the available examples!

## Documentation

### ADXL345 Class
#### Data types
* ADXL345_COMM_t
It defines the available communication methods for the sensor, so the user can choose between I2C or SPI communication. These values are used when creating an ADXL345 object on your project.

| Value | Description |
| ------ | ------ |
| ADXL345_COMM_I2C | Set the communication method to I2C protocol |
| ADXL345_COMM_SPI | Set the communication method to SPI protocol

#### Constructor
When creating an ADXL345 sensor on your project, there are one mandatory parameter, which is the communication type.

If you choose the I2C communication, nothing else needs to be set, unless you desire to activate the sensor debug messages. When choosing the SPI communication, the csPin must be set, otherwise the default SPI pin will be 0.

The debug option is disabled by default, and when enabled it sends the debug log during the sensor configuration operations, like setting a new range.

The serialDebugPort is the serial port that will transmit the debug messages. The default port is the Serial.

```cpp
ADXL345 (ADXL345_COMM_t commType,          // Communication used by the sensor
        uint8_t csPin=0,                  // CS Pin used for SPI communication
        bool debug=false                  // The debug mode
        Stream *serialDebugPort=&Serial); // Serial port where the debug messages will be printed
``` 

Usage:
```cpp
#define ADXL345_SPI_CS_PIN  5
/* Using sensor on SPI mode */
ADXL345 adxl(ADXL345_COMM_SPI, ADXL345_SPI_CS_PIN); // Normal mode
ADXL345 adxl(ADXL345_COMM_SPI, ADXL345_SPI_CS_PIN, true); // Debug messages enabled
ADXL345 adxl(ADXL345_COMM_SPI, ADXL345_SPI_CS_PIN, true, &Serial2); // Enabling the debug on Serial2 port

/* Using sensor on I2C mode */
ADXL345 adxl(ADXL345_COMM_I2C); // Normal mode
ADXL345 adxl(ADXL345_COMM_I2C, 0, true); // Debug messages enabled. Don't care about the cs pin.
ADXL345 adxl(ADXL345_COMM_I2C, 0, true, &Serial2); // Enabling the debug on Serial2 port
``` 

* powerOn()

When powered on, the sensor is converting acceleration data and storing it on it's memory.
You can use the configuration commands before or after powering on.

Usage:
```cpp
    adxl.powerOn();
``` 

* powerOff()

Stops the acceleration conversion.

Usage:
```cpp
    adxl.powerOff();
``` 
* setDataRate(float dataRate) / getDataRate()

These functions are used for setting or reading the current the output data rate, also named sampling frequency.
The table below lists the available output data rates and the required value to be set as dataRate parameter:

| Output Data Rate | dataRate |
| ------ | ------ |
| 6.25 Hz | 6.25 |
| 12.5 Hz | 12.5 |
| 25 Hz | 25 |
| 50 Hz | 50 |
| 100 Hz | 100 |
| 200 Hz | 200 |
| 400 Hz | 400 |
| 800 Hz | 800 |
| 1600 Hz | 1600 |
| 3200 Hz | 3200 |

If another value is requested or if this configuration is no set, the default value of 3200Hz will be used.

Usage:
```cpp
  adxl.setDataRate(100);
  float currentDataRate = adxl.getDataRate();
``` 

* setFullScaleRange(uint8_t fullScaleRange) / getFullScaleRange()

These functions are used to set or get the acceleration that corresponds the sensor full scale. 
The ADXL345 accelerometer has a 10 bit resolution, so it's output values may vary from 512 to -511.
If you don't set it or if you choose an invalid value, the default value will be 2G.
The available ranges are listed below:

| Full Scale Range | fullScaleRange parameter |
| ------ | ------ |
| 2 G | 2 |
| 4 G | 4 |
| 8 G | 8 |
| 16 G | 16 |

Usage:
```cpp
  adxl.setFullScaleRange(2);
  int range = adxl.getFullScaleRange();
``` 
* readX(), readY(), readZ()

These functions are used to read the acceleration. Each axis has an own function. The read values are relative to the current configured full scale range.

Usage:
```cpp
  int16_t x, y, z;
  /* Getting the sensor readings */
  x = adxl.readX();
  y = adxl.readY();
  z = adxl.readZ();
``` 

* getDeviceId()

This function returns the device ID byte. On this sensor, the device ID is 0xE5h. It's useful to detect if the sensor is working.

Usage:
```cpp
byte devId = adxl.getDeviceId();
``` 

* enableDebug(), disableDebug(), isDebugEnabled()

Enable, disable or check if the debug through the serial port is enabled.

Usage:
```cpp
  adxl.enableDebug(); // Enable the debug via serial
  adxl.disableDebug(); // Disable the debug via serial
  bool debug = adxl.isDebugEnabled(); // Check if the debug is enabled
``` 
* setSerialDebugPort(Stream *port)

Set the serial port used for debug.

Usage:
```cpp
    adxl.setSerialDebugPort(&Serial2);
``` 

## External References

[1] [__ADXL345 datasheet - Analog Devices__](http://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf)