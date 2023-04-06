//Author Nadhif Fauzil A
//basic Rain Sensor
//Using I2C LCD Analog Pin = SDA A4 SCL A5
//Servo Pin = 7
//Infrared Obsctacle pin = 2
//Rain Sensor Pin = 8
//Test Mode Pin = 3
//LED Green = 9
//LED Red = 6


#include <Servo.h>
#include <LiquidCrystal_I2C.h>
 #include <Wire.h> 
LiquidCrystal_I2C lcd(0x20, 16, 2);
Servo myservo;
int rainPin = 8;
int ir = 2;
int irbatas;
int testsr;
int tingkathujan;
int pos = 0;  
int testservo = 3;  

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(3,0);
  lcd.print("TURNING ON");
  myservo.attach(7);
  pinMode(rainPin, INPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop() {
testsr = digitalRead(testservo);
if (testsr == HIGH){
  digitalWrite(6, HIGH);
 digitalWrite(9, HIGH);
  lcd.clear();
lcd.setCursor(4,0);
lcd.print("TEST MODE");
for (pos = 0; pos <= 180; pos += 1) { 
 myservo.write(pos);           
    lcd.setCursor(7,1);
 lcd.print(pos);
    delay(10);  
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);
     lcd.setCursor(7,1);
 lcd.print(pos);             
    delay(10);                       
  }
  
  }
}
else {
  irbatas = digitalRead(ir);
  tingkathujan = digitalRead(rainPin);
if(tingkathujan == HIGH){
lcd.setCursor(6,1);
lcd.print("HUJAN");  
delay(500);
lcd.clear();
lcd.setCursor(3,0);
lcd.print("PERINGATAN");
delay(500);
lcd.clear();
digitalWrite(6, HIGH);
 digitalWrite(9, LOW);
 if (irbatas == LOW){
myservo.write(-360); 
 }

}
else{
lcd.setCursor(3,0);
  lcd.print("Rain Sensor");
lcd.setCursor(6,1);
lcd.print("CERAH");
myservo.write(360); 
digitalWrite(6, LOW);
digitalWrite(9, HIGH);


}
}
}


