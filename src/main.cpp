#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3);
int data;
int loopCounter = 0;
int delayTime = 250;

void setup()
{
  //Starting software serial at 9600 Baudrate
  BTserial.begin(9600);
}

void loop()
{
  loopCounter++;

  if (BTserial.available() > 0)
  {
    //If you send not just a char but a whole word from the paired device, you must change "read" to "readString" and type of the variable "data" to String.
    //e.g. https://git.io/JtaYU
    data = BTserial.read();
  }

  //Every second the Arduino will send data to other device. You can set a new frequency by changing not only "loopCounter" but also "delayTime".
  if (loopCounter == 4)
  {
    //Reseting loopCounter
    loopCounter = 0;

    if (data == 'a')
    {
      //It is important to use "println" instead of "print" or "write"!
      BTserial.println("pressed a!");
    }
    else if (data == 'b')
    {
      //It is important to use "println" instead of "print" or "write"!
      BTserial.println("pressed b!");
    }
    else if (data == 'c')
    {
      //It is important to use "println" instead of "print" or "write"!
      BTserial.println("pressed c!");
    }
    else
    {
      //It is important to use "println" instead of "print" or "write"!
      BTserial.println("no match!");
    }
  }
  delay(delayTime);
}