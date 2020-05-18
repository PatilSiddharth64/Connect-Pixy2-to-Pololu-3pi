#include <OrangutanMotors.h>
#include <SPI.h>

char message =' ';

void setup() 
{
  Serial.begin(19200);
}

void loop()
{
  if (Serial.available())
  {
    char message=Serial.read();
    if(message=='1')
    {
      OrangutanMotors::setSpeeds(125,125);
    }
    if(message=='2')
    {
      OrangutanMotors::setSpeeds(-125,-125);
    }
    if(message=='3')
    {
      OrangutanMotors::setSpeeds(125,-125);
    }
    if(message=='4')
    {
      OrangutanMotors::setSpeeds(-125,125);
    }
    if(message=='5')
    {
      OrangutanMotors::setSpeeds(0,0);
    }
  }
  delay(5);
}
