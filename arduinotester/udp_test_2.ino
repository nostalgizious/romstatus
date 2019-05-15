#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid ="Noobmaster69";
const char* password = "lwxi5828";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.8";
const int udpPort = 16969;

void setup()
{ 
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
  const char* test = "magnus";
 
  int romNummer = 216;
  int co2PPM = 369;
  int tempC = 223;
  int humidity = 79;
  int irSensor = 1;
  int packetSize = Udp.parsePacket();
    // receive incoming UDP packets
    delay(1000);
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
