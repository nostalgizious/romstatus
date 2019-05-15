#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid ="AndroidAP";
const char* password = "eesc5126";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.17";
const int udpPort = 51110;
int siste = 1;

void setup()
{ 
  pinMode(16, INPUT);
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
  int val = digitalRead (16);
  if (val == HIGH){
  Serial.println("x");
  siste = 1;
  delay(10);
  }
  else if (siste == 1){
    Serial.println("o");
    delay(10);
    siste = 0;
   }
  else{
    delay(10);
  }
  
  }
