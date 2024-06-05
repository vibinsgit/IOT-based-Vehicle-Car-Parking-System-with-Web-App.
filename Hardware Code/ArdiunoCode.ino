#include <SoftwareSerial.h>

SoftwareSerial nodemcu(2,3);

int slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino
int slot2_ir_s = 5;// parking slot1 infrared sensor connected with pin number 5 of arduino
int slot3_ir_s = 6;// parking slot1 infrared sensor connected with pin number 6 of arduino

String sensor1;
String sensor2;
String sensor3;


String cdata =""; // complete data, consisting of sensors values

void setup()
{
Serial.begin(9600);
nodemcu.begin(9600);

pinMode(slot1_ir_s, INPUT);
pinMode(slot2_ir_s, INPUT);
pinMode(slot3_ir_s, INPUT);

}

void loop()
{

slot1();
slot2();
slot3();
 
   cdata = cdata + sensor1 +"," + sensor2 + "," + sensor3 + ","; // comma will be used a delimeter
   Serial.println(cdata);
   nodemcu.println(cdata);
   delay(6000); // 100 milli seconds
   cdata = "";
digitalWrite(slot1_ir_s, HIGH);
digitalWrite(slot2_ir_s, HIGH);
digitalWrite(slot3_ir_s, HIGH);
}


void slot1() // slot1
{
  if( digitalRead(slot1_ir_s) == LOW)
  {
  sensor1 = "255";
 delay(200);
  }
  if( digitalRead(slot1_ir_s) == HIGH)
{
  sensor1 = "0"; 
 delay(200); 
}

}

void slot2() // slot2
{
  if( digitalRead(slot2_ir_s) == LOW)
  {
  sensor2 = "255";
  delay(200);
  }
  if( digitalRead(slot2_ir_s) == HIGH) 
  {
  sensor2 = "0"; 
 delay(200);
  }
}

void slot3() // slot3
{
  if( digitalRead(slot3_ir_s) == LOW)
  {
  sensor3 = "255";
  delay(200);
  }
  if( digitalRead(slot3_ir_s) == HIGH) 
  {
  sensor3 = "0"; 
 delay(200);
  }
}