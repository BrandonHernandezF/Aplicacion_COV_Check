#include "FirebaseESP8266.h"  //Librerías
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "tc1004b-8315e-default-rtdb.firebaseio.com/" //HOST de base de datos
#define FIREBASE_AUTH "XBDrMFUUHhqPxPyzngMspWsBJdnavRREUv8fBJMQ" //Clave de base de datos
#define WIFI_SSID "Tec-IoT" //Red Wifi
#define WIFI_PASSWORD "spotless.magnetic.bridge" //Password
#define TEMPERAT D4 //Asignación de entrada
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <Adafruit_Sensor.h> //Librería para sensor de temperatura
#include <DHT.h>
#include <DHT_U.h>
 
DHT dht(D4, DHT11); //Asignación del sensor de temperatura y tipo de sensor
uint32_t delayMS; 
 
float Lectura=0; //Lectura con valor de 0
int estadoDistancia = 0;
 
FirebaseData firebaseData; //Declaración de la Base de datos
 
LiquidCrystal_I2C lcd(0x27,16,2); //Declara objeto pantalla LCD
 
void setup()
{
  Serial.begin(9600); //Inicia monitor serie
  dht.begin(); //Inicia sensor de temperatura
  lcd.init(); //Inicia lcd
  lcd.backlight(); //Tipo de luz
  delay(2000); //Retraso de 2 segundos
  Serial.println('\n'); //Paso de espacio
  pinMode(D0, INPUT);
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //Inicio de red wifi y conexión
  Serial.print("Connecting to Wi-Fi -->"); //texto de conección
  Serial.print(WIFI_SSID); Serial.println(" ...");
 
  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)// Comprobar hasta que esté conectado
  {
      delay(1000);
      Serial.print(++teller); Serial.print(' ');
  }
 
  Serial.println('\n');
  Serial.println("WiFi conectado!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // Inicia la base de datos
  delay(10);
}
 
void sensorUpdate() { // Lee la temperatura y la asigna en la base de datos
    int cero = 0;
    Lectura=dht.readTemperature();
    if(Lectura==NULL)
    {
       Firebase.setInt(firebaseData, "/TEMPERAT", cero);
    }
    else
    {
       Firebase.setFloat(firebaseData, "/TEMPERAT", Lectura);
    }
    Serial.println(Lectura);
    delay(10);
}
 
void loop() {
  sensorUpdate();
if (Lectura!=NULL)
  {
   // Entra a la función sensorUpdate
  delay(delayMS);
  lcd.setCursor(0,0); // Escritura en la primera fila
  lcd.print("Temperatura:");
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(Lectura); // Imprime la lectura de la temperatura en la pantalla lcd.
  lcd.print("C");
  }
  else{
  
  lcd.setCursor(0,0); // Escritura en la primera fila
  lcd.print("");
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("");
  }
  delay(1000);

}
