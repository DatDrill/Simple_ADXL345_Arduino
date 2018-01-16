#include <Simple_ADXL345.h>

/* Using microseconds because for higher sampling
   frequencies the millis() won't be enough
*/
uint32_t lastReadingTime = micros();

/*
   For 800 Hz, we have 1.25ms between samples
   or 1250 microseconds.

   The time for a dataRate in microseconds is:
   readingIntervalMicroseconds = 1000000/dataRate
*/
uint16_t readingIntervalMicroseconds = 1250;

uint32_t taskLastTime = 0;
uint16_t taskIntervalMilliseconds = 1000;
bool ledState = false;

ADXL345 adxl(ADXL345_COMM_I2C);

void readData()
{
  int16_t x, y, z;

  x = adxl.readX();
  y = adxl.readY();
  z = adxl.readZ();

  /* Printing data in a excel friendly way */
  Serial.print(micros());
  Serial.print(";");
  Serial.print(x);
  Serial.print(";");
  Serial.print(y);
  Serial.print(";");
  Serial.println(z);
}

void setup()
{
  /* On higher sampling rates, it's better to boost our Serial baud rate */
  // Serial.begin(9600);
  Serial.begin(230400);

  /* Setting up the sensor */
  adxl.powerOn();
  adxl.setFullScaleRange(8);
  adxl.setDataRate(800);

  pinMode(13, OUTPUT);
}

void loop()
{
  /* If micros reset.... It happens every ~1h10min */
  if(lastReadingTime > micros())
  {
    lastReadingTime = micros(); 
  }
  
  if (micros() - lastReadingTime >= readingIntervalMicroseconds)
  {
    readingIntervalMicroseconds = micros();
    readData();
  }

  if(millis() - taskLastTime >= taskIntervalMilliseconds)
  {
    taskLastTime = millis();    
    /* Place your main task here. Remember: No delays! */

    /* NOTE:
     *  On Arduino UNO, Nano and ProMini the Onboard led pin
     *  is used on SPI communication. Don't forget!
     */
    ledState = !ledState;
    digitalWrite(13, ledState);

  }

}