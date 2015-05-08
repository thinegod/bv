# #include <SoftwareSerial.h>
SoftwareSerial dbgSerial(10, 11); // RX, TX
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  dbgSerial.begin(9600); 
  dbgSerial.println("ESP8266 Demo");
  //test if the module is ready
  //Serial.println("AT+RST");

}
void loop()
{

//  if(dbgSerial.available())
//  {
//   char s =dbgSerial.read();
//   Serial.write(s); 
//   dbgSerial.write(s);
//  }
  delay(1000);
  Serial.print("AT+CIPMUX=1\r\n");
  delay(1000);
  Serial.print("AT+CIPSERVER=1,4444\r\n");
  //delay(1000);
  if(Serial.available())
  {
    dbgSerial.println(Serial.read());
    dbgSerial.println(Serial.available());
  }
}

