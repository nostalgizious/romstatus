#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
// Henter fra biblioteker

const char* ssid ="AndroidAP"; //Skriv inn nettverksnavn i anførselstegnene
const char* password = "eesc5126"; //Skriv inn passordnavn i anførselstegnene

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.17"; //Skriv inn IP-adressen til mottakeren i anførselstegnene
const int udpPort = 53439; //Skriv inn UDP-porten til mottakeren

int sensor = 5; //PIR-sensoren sin inputpin____ Digital-5 = D2 pinen på ESP8266
int buttonpin = 0; //Knappen sin inputpin____Analog 0

//VARIABLER
int tid = 0; 
int statuz = 0;
int avlesning = 0; 
int timer = 500;        
int val=0;
int bval = 0;
//VARIABLER

void setup()
{ 
  pinMode(sensor, INPUT);       //Setter pinen sensoren er koblet til i som input for å ta imot data
  Serial.begin(9600); //Starter serialmonitoren for lett feilsøking

  Serial.printf("Connecting to %s ", ssid); //"connecting to internet"
  WiFi.begin(ssid, password); //Kobler seg til nettet
  while (WiFi.status() != WL_CONNECTED) //Denne while-loopen lager en "......." mens den kobler seg til nettet
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected"); //Når den har koblet seg på nettet sier den ifra
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  int bval = analogRead(buttonpin); //Lager en verdi bval ut av inputen til knappen
  int val = digitalRead(sensor); //Lager en verdi bval ut av inputen til PIR-sensoren
  if (bval > 200){ //Hvis knappen er trykt in vil den analoge verdien være over 200 og if-loopen starter
   Serial.println("bval");
   int avlesning = 1; //Avlesning er verdien som UDP senderen bruker når den ser om rommet er ledig eller ikke. 1=opptatt 0=ledig
   delay(300); //Doknappen er stilt inn på 300000ms som er 5 min
  }
  
        //Seitter verdien "val" til den den leser fra "sensor" som er om det er noen i rommet(HIGH) eller ikke(LOW)
else {
if(val == HIGH){
    for (tid = 0; tid < 600; tid++){ //ser sensoren noe vil den si ifra at det er noen der i 
        Serial.println("1");
        int avlesning = 1;
        delay(10);
        
      }
    }
  
  

else if (val == LOW) {        //dersom "val" er "LOW", altså om det ikke er noen i rommet kjører den koden under 
    int number;
    for (number = 0; number < timer; number++) {        //hvis den ike registerer at det er noen i rommet vil den sjekke i "timer" sekunder om det er noen i rommet
      int val = digitalRead(sensor);
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
 
 
  if(avlesning != statuz)
  {
    const char* test = "magnus";
  int romNummer = 216;
  int co2PPM = 369;
  int tempC = 223;
  int humidity = 79;
  int irSensor = avlesning;
  int packetSize = Udp.parsePacket();
 
   int statuz = avlesning; 

   int irSensors = statuz;
   
    Udp.beginPacket(udpAddress, udpPort);
    Udp.print(romNummer);
    Udp.write(":");
    Udp.print(co2PPM);
    Udp.write(":");
    Udp.print(tempC); 
    Udp.write(":");
    Udp.print(humidity);
    Udp.write(":");
    Udp.print(irSensor);
    Udp.write(":");
    Udp.endPacket();

  }
  else if(avlesning = statuz)
  {
    int statuz = avlesning;
    Serial.println("you've yee'd your last haw");
  }
  }
