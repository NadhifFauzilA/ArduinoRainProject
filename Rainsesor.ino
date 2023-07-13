#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//AUTO CLOTHESLINE PROGRAM FOR ARDUINO
//BY ARABIS GROUP REV 3
//FINAL PROJECT KOMUNIKASI DATA SEMESTER 2


LiquidCrystal_I2C lcd(0x27, 16, 2); 
//PIN 
#define rainsensor 10
#define irsensor1 8
#define irsensor2 9
#define ledred 2
#define ledyellow 3
#define ledgreen 4
#define in1 6
#define in2 7
int statuscuaca;
int irstatus1;
int irstatus2;

void setup()
{
	// INISIALISASI
	lcd.begin();
	lcd.backlight();
  lcd.setCursor(0,0);
	lcd.print("AUTO CLOTHESLINE ");
  lcd.setCursor(2,1);
  lcd.print("ARABIS GROUP");
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(rainsensor, INPUT);
  pinMode(irsensor1, INPUT);
  pinMode(irsensor2, INPUT);
  Serial.begin(9600);
  delay(1000);
  lcd.clear();
}
void motorright()
{
  lcd.setCursor(6,1);
  lcd.print("| MOTOR ON");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(ledyellow, HIGH);
}
void motorleft()
{
  lcd.setCursor(6,1);
  lcd.print("| MOTOR ON");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(ledyellow, HIGH);
}
void motoroff()
{
  lcd.setCursor(6,1);
  lcd.print("| MOTOR OF");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ledyellow, LOW);
}
void hujan() 
{
  lcd.setCursor(0,0);
	lcd.print("AUTO CLOTHESLINE ");
  lcd.setCursor(0,1);
	lcd.print("HUJAN");
  digitalWrite(ledred, HIGH);
  digitalWrite(ledgreen, LOW);
  irstatus1 = digitalRead(irsensor1);
  irstatus2 = digitalRead(irsensor2);
  if (irstatus2 == 0) 
  {
   motorleft();
  }
  else if (irstatus1 == 0)
  {
    motoroff();
  }
}
void cerah()
{
  lcd.setCursor(0,0);
	lcd.print("AUTO CLOTHESLINE ");
  lcd.setCursor(0,1);
	lcd.print("CERAH");
  digitalWrite(ledred, LOW);
  digitalWrite(ledgreen, HIGH);
  irstatus2 = digitalRead(irsensor2);
  irstatus1 = digitalRead(irsensor1);
  if(irstatus1 == 0) 
  {
      motorright();
  }
  else if (irstatus2 == 0)
  {
    motoroff();
  }
}
void loop()
{
      statuscuaca = digitalRead(rainsensor);
      if (statuscuaca == 0) 
      {
        hujan();
      }
     else if (statuscuaca == 1)
     {
    cerah();
     }
}
