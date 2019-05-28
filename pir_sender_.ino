#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
// Henter fra biblioteker

const char* ssid ="AndroidAP";//Skriv inn nettverksnavn i anførselstegnene
const char* password = "eesc5126";//Skriv inn passordnavn i anførselstegnene

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.17";//Skriv inn IP-adressen til mottakeren i anførselstegnene
const int udpPort = 49194;//Skriv inn UDP-porten til mottakeren


int sensor = 5; //PIR-sensoren sin inputpin____ Digital-5 = D2 pinen på ESP8266
int buttonpin = 0;//Knappen sin inputpin____Analog 0
  //bestemmer variabler for pinene som blir brukt i programmet slik at de lett kan endres



int statuz = 0;


int scantid = 100;   //Setter hvor lang tid den vil sjekke om rommet er ledig før den setter rommet som ledig
int val = 0;              
int i = 0;
int bval = 0;
int avlesning = 0;   //Avlesning er variabelen som bestemmer om et rom er ledig eller ikke. 0=ledig, 1=opptatt
int dotid = 300;  //Tiden du får når du trykker inn doknappen.
int led = 4;




void setup()
{ 
  pinMode(sensor, INPUT);       //Forteller mikrokontrollere at den skal få verdier fra "sensor", setter pinen sensoren er koblet til i som input for å ta imot data
  Serial.begin(9600);//Starter serialmonitoren for lett feilsøking
  Serial.println();

  Serial.printf("Connecting to %s ", ssid); //"connecting to internet"
  WiFi.begin(ssid, password); //Kobler seg til nettet
  while (WiFi.status() != WL_CONNECTED)//Denne while-loopen lager en "......." mens den kobler seg til nettet
 
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
    int avlesning = 1; //avlesningsvariabelen blir 1 noe som indikerer at den er opptatt
   int irSensor = avlesning; //setter irSensor variabelen lik avlesning.
   Udp.beginPacket(udpAddress, udpPort); //Start å skrive en UDP-pakke som skal sendes.
   Udp.write("irSensor:"); //Gi UDP-pakken et navn så det er enkelt å skille pakkene.
   Udp.print(irSensor); //Gir UDP-pakken en verdi som viser om det er ledig eller opptatt
   Udp.endPacket(); //Avslutt UDP-sendinga
   delay(dotid);//Doknappen er stilt inn på en tid, bestemt i variablene. Den er foreløpig 300000ms=5min
  }
  
        //Seitter verdien "val" til den den leser fra "sensor" som er om det er noen i rommet(HIGH) eller ikke(LOW)
else {
if(val == HIGH){
    for (i = 0; i < 50; i++){ //ser sensoren noe vil den si ifra at det er noen der i 
        int avlesning = 1;
        Serial.println("1");
        int irSensor = avlesning;
        Udp.beginPacket(udpAddress, udpPort);// forbreder udp til å sende en packet 
        Udp.write("irSensor:"); // skriver et som er inne i "" 
        Udp.print(irSensor);  //sender verdien som heter irSensor 
        Udp.endPacket(); // avslutter pakken 
        delay(10); // setter inn et lite delay 
        
      }
    }
  
  

else if (val == LOW) {        //dersom "val" er "LOW", altså om det ikke er noen i rommet kjører den koden under 
    int x;
    for (x = 0; x < scantid; x++) {        //hvis den ike registerer at det er noen i rommet vil den sjekke i "sacntid" sekunder om det er noen i rommet
      int val = digitalRead(sensor); // variabel som heter val, verdi = info som blir henta far pir sensor 
      if (val == HIGH) { // lager en if løkke som ser etter info fra pir esnsoren
      break;        //dersom det bli merket bevegelse stubber den for loopen
      }
      else {        //dersom den fortsatt ikke merker noe venter den i et sekun
        ;
        delay(1);
       } 
       }
       if (x < scantid) {       //hvis for-loopen har blitt brutt slik at "number" er ulik "scantid" gjør den ingen ting og forsetter tilbake til starten
       }
       else {        //ellers hvis "number" er lik (eller større enn) scantid vil bytte hvilken led som er på
      int avlesning = 0;
      int irSensor = avlesning;
      Serial.println(irSensor);    //printer "no motion detected" slik at det blir enkelt å feilsøke

    }
  }
}
  int romNummer = 216;  // variabel med navn romNummer som har verdi 216 (dette er eksempel på en verdi)
  int co2PPM = 369;  // variabel med navn co2PPM som har verdi 369 (dette er eksempel på en verdi)
  int tempC = 223; // variabel med navn tempC som har verdi 223 (dette er eksempel på en verdi)
  int humidity = 79;  // variabel  med navn humidity som har verdi 79 (dette er eksempel på en verdi)
  int irSensor = val; // variabel med navn irSensor som har verdi = val
  int packetSize = Udp.parsePacket(); // lager en verdi med navnet packetSize
    // receive incoming UDP packets
    delay(100);
   
    Udp.beginPacket(udpAddress, udpPort); // forbreder udp til å sende en packet
    Udp.print(romNummer);  //sender verdien som heter romNummer (samme under)
    Udp.write(":"); // skriver et som er inne i "" (samme under)
    Udp.print(co2PPM);
    Udp.write(":");
    Udp.print(tempC); 
    Udp.write(":");
    Udp.print(humidity);
    Udp.write(":");
    Udp.print(irSensor);
    Udp.write(":");
    Udp.endPacket(); // avslutter pakken 
    delay(100); // putter in delayer mellom hver packet for at den ikke skal hope seg opp 
    Serial.println(irSensor); // printer verdien til monitoren for å feilteste 

    
}
