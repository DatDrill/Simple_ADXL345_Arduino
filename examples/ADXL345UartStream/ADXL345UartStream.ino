#include <ADXL345.h>

#define ADXL345_SPI_CS_PIN 5

/* Starting the sensor in the SPI mode */
ADXL345 adxl(ADXL345_COMM_SPI, ADXL345_SPI_CS_PIN);

void setup()
{
    Serial.begin(115200);

    /* Setting up the sensor */
    adxl.powerOn();
    adxl.setFullScaleRange(8);
    adxl.setDataRate(400);
}

void loop()
{
    /* Reading data */
    int16_t x,y,z;
    
    x = adxl.readX();
    y = adxl.readY();
    z = adxl.readZ();

    /* Printing data in a excel friendly way */
    Serial.print(millis());
    Serial.print(";");
    Serial.print(x);
    Serial.print(";");
    Serial.print(y);
    Serial.print(";");
    Serial.println(z);

   delay(25);
}