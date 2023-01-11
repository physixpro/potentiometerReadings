#include <Arduino.h>
#define MY_LED A5
int readDelay = 1000;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MY_LED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A4);

  // Equations

  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print(voltage);
  Serial.println(" potentiometer voltage reading");

  float current = (voltage / 461);
  Serial.print(current);
  Serial.println(" potentiometer current reading");

  float resistance = (voltage/current);
  Serial.print(resistance);
  Serial.println(" potentiometer resistance reading");

  float temperatureC = (voltage - 0.5) * 100;
  Serial.print(temperatureC);
  Serial.println(" degrees C is the temperature");

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.println(" degrees F is our temperature");
  Serial.println("     ");
  Serial.println("     ");

  digitalWrite(MY_LED, HIGH);
  delay(1000);
  digitalWrite(MY_LED, LOW);
  delay(1000);

  delay(readDelay);
}