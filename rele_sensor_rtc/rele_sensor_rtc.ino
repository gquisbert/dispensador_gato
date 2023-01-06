#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 RTC;

//pin digital
byte Rele1 = 8; // Si utilizas un Arduino UNO Arduino MEGA}
//pin Analogico
byte SensorHumedad = 0;
int hora;
int minuto;
// the setup routine runs once when you press reset:
void setup() {
  // initializing RTC
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));

  // initialize el pin del rele como salida
  pinMode(Rele1, OUTPUT);
  digitalWrite(Rele1, HIGH);
  //inicializamos sensor de Humedad
  Serial.begin (9600);

}

// the loop routine runs over and over again forever:
void loop() {
  ///RTC
  DateTime now = RTC.now();
  hora = now.hour();
  minuto = now.minute();

  if (hora == 6 && minuto < 5) {
    //Serial.println(hora);
    //Serial.println(minuto);

    int humedad = analogRead(SensorHumedad);

    int porcentaje = humedad / 10.23;
    Serial.println("El  porcentaje de humedad es :" + porcentaje);
    if (porcentaje  <= 100.00 && porcentaje >= 66) {
      Serial.print("El sensor detecta que la maceta esta Seca, su valor es: ");
      Serial.println(porcentaje);
      digitalWrite(Rele1, LOW);   // activar el rele'
      Serial.println("encendido");
      delay(11000);               // esperar un segundo
      digitalWrite(Rele1, HIGH);    // apagar el rele'
      Serial.println("apagado");
    } else {
      Serial.print("El sensor detecta que la maceta esta Humeda o mojada, su valor es: ");
      Serial.println(porcentaje);
      digitalWrite(Rele1, HIGH);    // apagar el rele'
      Serial.println("apagado");
    }//fin del if  porcentaje <=100
  }//fin de if hora
//control de comida de gato
if (hora ==6 && minuto==0)  {
  
 }
if (hora ==11 && minuto==0)  {
  
 }
 if (hora ==16 && minuto==0)  {
  
 }
 if (hora ==21 && minuto==0)  {
  
 }
 
  delay(000);               // esperar un segundo
}//fin de loop
