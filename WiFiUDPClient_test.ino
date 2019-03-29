/*
 * Denne koden leser av PPM verdier for luftforurensning fra en MQ135 gasssensor, viser dette på en LCD skjerm og sender informasjonen over UDP
 */
// --- Oppsett til WiFi --- 
#include <WiFi.h>
#include "esp_wpa2.h" //wpa2 library for å koble til bedriftsnettverk
#include <WiFiUdp.h>
#define EAP_IDENTITY "username" // Brukernavnet ditt med 3 bokstaver fra for og etternavn og et 2-sifret tall
#define EAP_PASSWORD "password-" //Passordet

// --- LCD skjerm konfigurasjon ---
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
// --- Luftkvalitssensor ---
int sensor_avlesning;
int gammelVerdi = 0;


// --- WiFi nettverk brukernavn og passord ---
const char * ssid = "ssid";
const char * networkUsnm = "username"; //Samme brukernavn
const char * networkPswd = "password-"; //Samme passord

// --- IP addresse til å sende UDP data til ---
const char * udpAddress = "10.25.9.178";
const int udpPort = 16969;

// --- Teste forbindelse --- 
boolean connected = false;

// --- Type til UDP library ---
WiFiUDP udp;

int counter = 0;

// --- Definsere pins til sensorer
//int lcdPin = 39;
int sensorPin = 36;

void setup(){
  // Initilize hardware serial:
  Serial.begin(9600);
  
  //Connect to the WiFi network
  //, networkUsnm, networkPswd
  connectToWiFi(ssid);
  pinMode(sensorPin,INPUT);
  //pinMode(lcdPin, OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop(){
  //only send data when connected 
  sensor_avlesning = digitalRead(sensorPin);
  Serial.print(sensor_avlesning);
  if(connected){
    //Send a packet
  /*  udp.beginPacket(udpAddress,udpPort);
    udp.printf("Verdi:",avlesning); */
    while (digitalRead(sensorPin) != gammelVerdi){
      udp.beginPacket(udpAddress,udpPort);
      udp.printf("%d",sensor_avlesning);
      udp.endPacket();
      Serial.println(sensor_avlesning);
      gammelVerdi = digitalRead(sensorPin);
      
  }
  /*
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ArQ=");
  lcd.print(sensor_avlesning,DEC);
  lcd.print(" PPM");
  lcd.println("       "); 
  lcd.print("  ");
  delay(100);        */      
  }
  //Wait for 1 second
}
//, const char * networkUsnm, const char networkPswd
void connectToWiFi(const char * ssid){
  Serial.println("Connecting to WiFi network: " + String(ssid));

  // delete old config
  WiFi.disconnect(true);
  //register event handler
  WiFi.onEvent(WiFiEvent);
  
  //Initiate connection
  WiFi.mode(WIFI_STA); //init wifi mode
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
  esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter++;
    if(counter>=60){ //after 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: "); 
  Serial.println(WiFi.localIP()); //print LAN IP
  }

//wifi event handler
void WiFiEvent(WiFiEvent_t event){
    switch(event) {
      case SYSTEM_EVENT_STA_GOT_IP:
          //When connected set 
          Serial.print("WiFi connected! IP address: ");
          Serial.println(WiFi.localIP());  
          //initializes the UDP state
          //This initializes the transfer buffer
          udp.begin(WiFi.localIP(),udpPort);
          connected = true;
          break;
      case SYSTEM_EVENT_STA_DISCONNECTED:
          Serial.println("WiFi lost connection");
          connected = false;
          break;
    }
}
