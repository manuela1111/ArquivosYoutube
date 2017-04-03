/*
AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)
Editado por Manuela Amaral e Luis Paulo
*/
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11); // RX | TX

void setup() 
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  delay(1);
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available()) {
    //Serial.print("Recebido pelo bt: ");
    char comando = BTSerial.read();
    Serial.write(comando);
    //Serial.println("");

    if (comando == 'V') {
      digitalWrite(2, HIGH);
    } else if (comando == 'v') {
      digitalWrite(2, LOW);
    }
  }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
   // Serial.print("Recebido pelo terminal: ");
    BTSerial.write(Serial.read());
    //Serial.println("");
  }
}
