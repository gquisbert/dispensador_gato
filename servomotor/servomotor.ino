#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
RTC_DS1307 RTC;

int hora;
int minuto;
int pos;
Servo myservo;
int pin = 8;                //pin digital SERVO

int h1 = 6;
int h2 = 12;
int h3 = 18;

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
  //myservo.write(90);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.begin(9600);
}

void loop() {
   //myservo.write(90);
    delay(10);
    
  // put your main code here, to run repeatedly:
     DateTime now = RTC.now();
   Serial.print("hora en decimal: ");
   Serial. println(now.hour(),DEC);

   Serial.print("minuto en decimal: ");
   Serial. println(now.minute(),DEC);

Serial.print("dia en decimal: ");
   Serial. println(now.day(),DEC);

  Serial.print("HORA 1 en decimal: ");
   Serial. println(h1,DEC);
  Serial.print("HORA 2 en decimal: ");
   Serial. println(h2,DEC);  
  Serial.print("HORA 3 en decimal: ");
   Serial. println(h3,DEC);
 Serial.print("r1 en decimal: ");
   Serial. println(r1,DEC);
 Serial.print("r2 en decimal: ");
   Serial. println(r2,DEC);
   Serial.print("r3 en decimal: ");
   Serial. println(r3,DEC);
   
  Serial.print("minuto de comida: ");
   Serial. println(minutoComida,DEC);
   
  Serial.print("Dia anterior: ");
   Serial. println(diaAnterior,DEC);
   hora= now.hour();
   minuto=now.minute();
   dia= now.day();
  if (dia != diaAnterior) {
    //Serial.println(dia);
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    diaAnterior = dia;


 
  }
  if (hora == h1  && minuto == minutoComida && r1 == 0) {
    pos=90;
  while (pos<=180){
    myservo.write(pos);  
    delay(25);
    pos+=1;
    }
    pos=180;
  while (pos>=90){
    myservo.write(pos);  
    delay(10);
    pos-=1;
    } 
    
    r1 = 1;
  }//fin endif
  if (hora == h2 && minuto == minutoComida && r2 == 0) {
pos=90;
  while (pos<=180){
    myservo.write(pos);  
    delay(20);
    pos+=1;
    }
    pos=180;
  while (pos>=90){
    myservo.write(pos);  
    delay(10);
    pos-=1;
    } 
    
    r2 = 1;
  }//fin endif
  if (hora == h3 && minuto == minutoComida && r3 == 0) {
    pos=90;
  while (pos<=180){
    myservo.write(pos);  
    delay(15);
    pos+=1;
    }
    pos=180;
  while (pos>=90){
    myservo.write(pos);  
    delay(10);
    pos-=1;
    } 
    
    r3 = 1;
    //Serial.println(r3);
  }//fin endif

delay(5000);
}//fin loop
