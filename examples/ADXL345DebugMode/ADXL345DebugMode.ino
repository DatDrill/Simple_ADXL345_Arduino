#include <Simple_ADXL345.h>

/* Starting the sensor in the I2C mode */
ADXL345 adxl(ADXL345_COMM_I2C, 0, true);

uint8_t range = 1;
float rate = 100;

void setup()
{
    Serial.begin(9600);

    /* Setting up the sensor */
    adxl.powerOn();
}

void loop()
{

    Serial.println(" === Setting a new config === ");
    adxl.setFullScaleRange(range);
    range++;
    if(range > 8) range = 1;

    adxl.setDataRate(rate);
    rate = rate + 100;
    if(rate > 1600) rate = 100;
    Serial.print("\n\n");
    delay(2500);
}