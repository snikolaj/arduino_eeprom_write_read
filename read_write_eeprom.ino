#include <Wire.h>    
 
byte disk1 = 0x50;
#define pin1 4
#define pin2 3
#define pin3 2
unsigned int address = 0;
void setup(void)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  Serial.begin(9600);
  Wire.begin();  
  const char* str = "I threw a wish in the well Don't ask me I'll never tell I looked at you as it fell And now you're in my way I'd trade my soul for a wish Pennies and dimes for a kiss I wasn't looking for this But now you're in my way Your stare was holding Ripped jeans, skin was showin' Hot night, wind was blowin' Where you think you're going baby? Hey, I just met you and this is crazy But here's my number, so call me maybe It's hard to look right at you baby But here's my number, so call me maybe Hey I just met you and this is crazy But here's my number, so call me maybe And all the other boys try to chase me But here's my number, so call me maybe You took your time with the call I took no time with the fall You gave me nothing at all But still you're in my way I beg and borrow and steal At first sight and it's real I didn't know I would feel it But it's in my way";
  int i = 0;
  for(i = 0; i < 1023; i++){
    if(i <= 255){
      writeEEPROM(disk1, i, str[i]);
    }else{
      if(i >= 256 && i <= 512){
        disk1 = 0x51;
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        writeEEPROM(disk1, i, str[i]);
      }else{
        if(i >= 512 && i <= 768){
        disk1 = 0x52;
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        writeEEPROM(disk1, i, str[i]);
      }else{
        if(i >= 768 && i <= 1024){
        disk1 = 0x53;
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, HIGH);
        writeEEPROM(disk1, i, str[i]);
      }
      }
      }
    } 
  }

  disk1 = 0x50;
  delay(1000);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  for(i = 0; i < 1023; i++){
    if(i <= 255){
      Serial.print((char)readEEPROM(disk1, address + i));  
    }else{
      if(i >= 256 && i <= 512){
        disk1 = 0x51;
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        Serial.print((char)readEEPROM(disk1, address + i));  
      }else{
        if(i >= 512 && i <= 768){
        disk1 = 0x52;
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        Serial.print((char)readEEPROM(disk1, address + i));  
      }else{
        if(i >= 768 && i <= 1024){
        disk1 = 0x53;
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, HIGH);
        Serial.print((char)readEEPROM(disk1, address + i));  
      }
      }
      }
    } 
  }
}
 
void loop(){
  delay(50);
}
 
void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) 
{
  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress);
  Wire.write(data);
  Wire.endTransmission();
 
  delay(5);
}
 
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) 
{
  byte rdata = 0xFF;
 
  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress);
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,1);

  delay(5);
  if (Wire.available()) rdata = Wire.read();
 
  return rdata;
}
