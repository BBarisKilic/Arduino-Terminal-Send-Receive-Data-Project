#include <Arduino.h>
#include <SoftwareSerial.h>

int data;
#define green_led 8
#define red_led 9

SoftwareSerial BTserial(2, 3);

void setup()
{
	pinMode(green_led, OUTPUT);
	pinMode(red_led, OUTPUT);
  BTserial.begin(9600); 
  Serial.begin(9600);
}

void loop()
{
	if(BTserial.available()>0)
  {
		data = BTserial.read();
  }
	  if (data == 'a'){
      BTserial.println("pressed a!");
	  } else if (data == 'b'){
      BTserial.println("pressed b!");
	  } else if(data == 'c'){
      BTserial.println("pressed c!");
	  } else{
	  	BTserial.println("no match!");
	  }
   delay(250);
  }