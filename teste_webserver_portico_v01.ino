#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ESP8266WebServer.h>

#include <SoftwareSerial.h>

#include "index.h"

#define LED D0
#define D7 13 // RX 
#define D8 15 // TX



const char* ssid = "LSM_NET";

const char* password = "lsm12345678";

ESP8266WebServer server(80);

SoftwareSerial mySerial(D7, D8); // RX = D7, TX  = D8


void handleRoot() 

{

 String s = webpage;

 server.send(200, "text/html", s);

}


void sensor_data() 

{

  Serial.begin(115200); // abre a porta serial, configura a taxa de transferência para 9600 bps
  mySerial.begin(115200);
  int dados;
 //int a = analogRead(A0);

 //int temp= a/4.35;


if (mySerial.available() > 0){
 
       
       dados = mySerial.read();
    
    String dados_pot = String(dados);
    mySerial.print(dados); // Imprime o caractere no monitor serial
    Serial.print(dados); // Imprime o caractere no monitor serial    
    Serial.write(dados);
    server.send(200, "text/plane", dados_pot);

 
} 


 //  int temp= a;
// String sensor_value = String(temp);

 //server.send(200, "text/plane", sensor_value);

}


void led_control() 

{

    mySerial.begin(115200);

 String state = "OFF";

 String act_state = server.arg("state");

 if(act_state == "1")
  

 {

  digitalWrite(LED,HIGH); //LED ON

  state = "ON";

  Serial.println(" MOTOR X");
   mySerial.println("1") ;

 }

 

  if(act_state == "0") {

 Serial.println(" MOTOR Y");  
  mySerial.println("2") ;

  }


  if(act_state == "2") {

 Serial.println(" MOTOR Z"); 
  mySerial.println("3") ; 

  }

    if(act_state == "3") {

 Serial.println(" DESLIGAR "); 
  mySerial.println("4") ; 

  }

    if(act_state == "4") {

 Serial.println(" LIGAR "); 
  mySerial.println("5") ; 

  }  

 server.send(200, "text/plane", state);

}


void setup(void)

{

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("");

  pinMode(LED,OUTPUT); 

  

  while (WiFi.status() != WL_CONNECTED)

  {

    Serial.print("Connecting...");

  }

  Serial.println("");

  Serial.print("Connected to ");

  Serial.println(ssid);

  Serial.print("IP address: ");

  Serial.println(WiFi.localIP());

 

  server.on("/", handleRoot);

  server.on("/led_set", led_control);

  server.on("/adcread", sensor_data); // valor  do sensor 

  server.begin();

}


void loop(void)

{

  server.handleClient();

}