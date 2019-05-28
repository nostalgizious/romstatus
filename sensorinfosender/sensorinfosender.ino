#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid ="AndroidAP";
const char* password = "eesc5126";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.17";
const int udpPort = 64317;

int tid = 0;
int sensor = 5;
int statuz = 0;
int avlesning = 0;
  //bestemmer variabler for pinene som blir brukt i programmet slik at de lett kan endres
int timer = 600;        //setter hvor lang tid den vil sjekke om rommet er ledig før den bytter om til grønt lys
int waittime = 10;
int val=0;

int buttonpin = 0;
int led = 4;
int bval = 0;

void setup()
{ 
  pinMode(sensor, INPUT);       //Forteller mikrokontrollere at den skal få verdier fra "sensor"
  pinMode(buttonpin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  int val = digitalRead(sensor);      //Seitter verdien "val" til den den leser fra "sensor" som er om det er noen i rommet(HIGH) eller ikke(LOW)

    int bval = analogRead(buttonpin);
  Serial.println(bval);
  if (bval > 200){
   digitalWrite(led, HIGH);
   Serial.println("1");
  }

else{
if(val == HIGH){
    for (tid = 0; tid < 500; tid++){
        Serial.println("1");
        
        int avlesning = 1;
        delay(10);
        
      }
    }
  
  

else if (val == LOW) {        //dersom "val" er "LOW", altså om det ikke er noen i rommet kjører den koden under 
    int number;
    for (number = 0; number < timer; number++) {        //hvis den ike registerer at det er noen i rommet vil den sjekke i "timer" sekunder om det er noen i rommet
      val = digitalRead(sensor);
      if (val == HIGH) {
      break;        //dersom det bli merket bevegelse stubber den for loopen
      }
      else {        //dersom den fortsatt ikke merker noe venter den i et sekun
        ;
        delay(1);
       } 
       }
       if (number < timer) {       //hvis for-loopen har blitt brutt slik at "number" er ulik "timer" gjør den ingen ting og forsetter tilbake til starten
       }
       else {        //ellers hvis "number" er lik (eller større enn) timer vil bytte hvilken led som er på
      int avlesning = 0;
      Serial.println("0");    //printer "no motion detected" slik at det blir enkelt å feilsøke

    }
  }
}
  const char* test = "magnus";
 
  int romNummer = 216;
  int co2PPM = 369;
  int tempC = 223;
  int humidity = 79;
  int irSensor = val;
  int packetSize = Udp.parsePacket();
    // receive incoming UDP packets
    delay(100);
    //Udp.beginPacket(udpAddress, udpPort);
    //Udp.write("test");
    //Udp.write(test);
    //Udp.endPacket();
    Udp.beginPacket(udpAddress, udpPort);
    Udp.write("romNummer:");
    Udp.print( romNummer);
    Udp.endPacket();
     delay(100);
    Udp.beginPacket(udpAddress, udpPort);
    Udp.write("co2PPM:");
    Udp.print( co2PPM);
    Udp.endPacket();
     delay(100);
    Udp.beginPacket(udpAddress, udpPort);
    Udp.write("tempC:");
    Udp.print( tempC);
    Udp.endPacket();
     delay(100);
    Udp.beginPacket(udpAddress, udpPort);
    Udp.write("humidity:");
    Udp.print( humidity);
    Udp.endPacket();
     delay(100);
    Udp.beginPacket(udpAddress, udpPort);
    Udp.write("irSensor:");
    Udp.print(irSensor);
    Udp.endPacket();
     delay(100);
    Serial.println(irSensor);
    
    //Serial.println(sensor_avlesning);
    //gammelVerdi = digitalRead(sensorPin);
    
}
