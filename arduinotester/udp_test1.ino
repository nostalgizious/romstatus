#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid ="Noobmaster69";
const char* password = "lwxi5828";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

const char * udpAddress = "192.168.43.233";
const int udpPort = 51110;

void setup()
{ 
  Serial.begin(115200);
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
  const char * test = "magnus";
  const char *isSensor = "1";
  int packetSize = Udp.parsePacket();
    // receive incoming UDP packets
    delay(1000);
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write(test);
    udp.write("%u",tall);
    Udp.endPacket();
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write("romNummer");
    udp.write("%u",romNumemr );
    Udp.endPacket();
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write("co2PPM");
    udp.write("%u",co2PPM);
    Udp.endPacket();
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write("tempC");
    udp.write("%u",temC);
    Udp.endPacket();
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write("humidity");
    udp.write("%u",humidity);
    Udp.endPacket();
    Udp.beginPacket(udpAddress,udpPort);
    Udp.write("irSensor");
    udp.write("%u",irSensor);
    Udp.endPacket();
    
    //Serial.println(sensor_avlesning);
    //gammelVerdi = digitalRead(sensorPin);
    
    
}
