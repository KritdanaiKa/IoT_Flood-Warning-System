#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <HCSR04.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pingPin = 13;
int inPin = 12;
double maxH = -1;
double waterlavel = 0;
int danger = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  HCSR04.begin(pingPin, inPin);
}

void loop() {
  double* distances = HCSR04.measureDistanceCm();
  if (distances[0] > maxH) {
    maxH = distances[0];
  }
  if (distances[0] >= 0) {
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print(" ");
    waterlavel = maxH - distances[0];
    //Serial.print("Height : ");
    //Serial.println(String(maxH));
    //Serial.print("Water Height : ");
    Serial.println(String(waterlavel));
    if(waterlavel >= 181){
      danger = 4;
    }
    else if (waterlavel >= 151){
      danger = 3;
    }
    else if (waterlavel >= 131){
      danger = 2;
    } 
    else {
      danger = 1;
    }
    
    //Serial.print(distances[0]);
    //Serial.print(" cm");
    //Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("Water: " + String(waterlavel) + "");
    lcd.setCursor(0, 1);
    lcd.print("Level: " + String(danger));
  }

  delay(1000);
}
