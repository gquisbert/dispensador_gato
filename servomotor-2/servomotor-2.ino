#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
RTC_DS1307 RTC;

int hora;
int minuto;
Servo myservo;
int pin = 8;//pin digital SERVO

int h1 = 6;
int h2 = 11;
int h3 = 16;
int h4 = 20;
int minutoComida = 29;
int diaAnterior = 1;
int dia;
int r1 = 0;
int r2 = 0;
int r3 = 0;
int r4 = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(pin);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
  Serial.begin(9600);
}

void loop() {
  Serial.println("servo");
   myservo.write(0);
    delay(1000);
    myservo.write(180);
    delay(10);
    myservo.write(130);
    delay(10);
    myservo.write(90);
    delay(1000);
  // put your main code h
}
