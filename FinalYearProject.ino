// Including libraries of Firebase and WiFi 
#include <FirebaseArduino.h>                                                // Firebase library
#include <ESP8266WiFi.h>                                                    // WiFi library

#define FIREBASE_HOST "myfirebaseapp-1239.firebaseio.com"                       // Link of API
#define FIREBASE_AUTH "mTpa9m1atfGoIHNxt6ibkUKOagh1WiJvHvPrsftC"            // Link of Database Secrets

#define WIFI_SSID "MSK"                                                     // WiFi's Username
#define WIFI_PASSWORD "Krishna0406"                                         // WiFi's Password

#define WIFI_LED D5                  //connect a led to any of the gpio pins of the board and replace pin_number with it eg. D4                      

int sensorPin = A0;
int sensorValue = 0;

void setup() {
  // Put your setup code here, to run once:
 
  //Start Serial Communication
  Serial.begin(9600);

  pinMode(WIFI_LED,OUTPUT);      //define pinmodes
    
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  //connect to wifi
  while (WiFi.status() != WL_CONNECTED) {           //wait till connected to WiFi
  delay(100);      digitalWrite(WIFI_LED,LOW);                     //Blink the light till connected to WiFi
      delay(100);
      digitalWrite(WIFI_LED,HIGH);
      Serial.print("."); 
      }
    
  Serial.println("");
  Serial.println("WiFi connected");
  digitalWrite(WIFI_LED,HIGH);  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);    //connect to Database
  Serial.println("connected");
  delay(1000);
  
}

void loop() {
  // Put your main code here, to run repeatedly:
  //sensorValue = analogRead(sensorPin);

  //Serial.println(sensorValue);
  
  //int randomNumber1 = random(150,850);
  int randomNumber2 = random(150,850);
  int randomNumber3 = random(150,850);
  int randomNumber4 = random(150,850);  
  //Firebase.setInt("Concentration1", sensorValue);
  Firebase.setInt("Concentration2", randomNumber2);
  Firebase.setInt("Concentration3", randomNumber3);
  Firebase.setInt("Concentration4", randomNumber4);
  delay(100);
}

