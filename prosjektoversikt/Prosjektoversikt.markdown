# Romstatus

---

*Et prosjekt av Magnus Hovda, Arvin Das, Martin S. Winther og Ferdinand O. Schnell*

![nettsideeksempel](vedlegg/nettsideeksempel.png)

<!-- TOC START min:1 max:3 link<!-- TOC START min:1 max:3 link:true asterisk:false update:true -->
- [Romstatus](#romstatus)
- [Prosjektbeskrivelse](#prosjektbeskrivelse)
- [Begrunnelse](#begrunnelse)
- [Kompetansemål](#kompetansemål)
  - [Teknologi og forskningslære 1](#teknologi-og-forskningslære-1)
    - [Den unge ingeniøren](#den-unge-ingeniøren)
    - [Den unge forskeren](#den-unge-forskeren)
    - [Teknologi, naturvitenskap og samfunn](#teknologi-naturvitenskap-og-samfunn)
    - [Design og produktutvikling](#design-og-produktutvikling)
- [Beskrivelse av funksjonalitet til deler](#beskrivelse-av-funksjonalitet-til-deler)
  - [Hvordan en NDIR CO~2~ sensor fungerer](#hvordan-en-ndir-co2-sensor-fungerer)
  - [Hvordan en PIR sensor fungerer](#hvordan-en-pir-sensor-fungerer)
- [Original tidsplan](#original-tidsplan)
  - [Uke 5](#uke-5)
  - [Uke 6](#uke-6)
  - [Uke 7](#uke-7)
  - [Uke 8](#uke-8)
  - [Uke 10](#uke-10)
  - [Uke 11](#uke-11)
  - [Uke 12](#uke-12)
  - [Utover året](#utover-året)
- [Logg](#logg)
  - [Uke 5](#uke-5-1)
  - [Uke 6](#uke-6-1)
  - [Uke 7](#uke-7-1)
  - [Uke 8](#uke-8-1)
  - [Uke 9](#uke-9)
  - [Uke 10](#uke-10-1)
  - [Uke 11](#uke-11-1)
  - [Uke 12](#uke-12-1)
  - [Uke 13](#uke-13)
- [Vedlegg](#vedlegg)
  - [Skjermbilde 1](#skjermbilde-1)
  - [Skjermbilde 2](#skjermbilde-2)
  - [Kode 3](#kode-3)
    - [luftkvalitetssender.pde](#luftkvalitetssenderpde)
    - [luftkvalitetslogger.py](#luftkvalitetsloggerpy)
  - [Skjermbilde 4](#skjermbilde-4)
  - [Kode 5](#kode-5)
    - [rom.ini](#romini)
    - [config.py](#configpy)
    - [postgresinsert.py](#postgresinsertpy)
  - [Illustrasjon 6-8](#illustrasjon-6-8)
  - [Illustrasjon 9-11](#illustrasjon-9-11)
  - [Illustrasjon 12-14](#illustrasjon-12-14)
  - [Illustrasjon 15-17](#illustrasjon-15-17)
  - [Bilde 18-20](#bilde-18-20)
  - [Bilde 21-22](#bilde-21-22)
  - [Illustrasjon 23-24](#illustrasjon-23-24)
  - [Bilde 25-26](#bilde-25-26)
  - [Kode 27-29](#kode-27-29)
    - [htmlOppdaterer.py](#htmloppdatererpy)
    - [oppdatererLib.py](#oppdatererlibpy)
    - [grupperomOversikt.html](#grupperomoversikthtml)
    - [oversiktGrupperom.css](#oversiktgrupperomcss)
    - [grupperomOversikt.js](#grupperomoversiktjs)
<!-- TOC END -->

# Prosjektbeskrivelse

Vi bygger en sensor som loggfører om det er bevegelse i et rom, temperatur, CO~2~ - nivå og luftfuktighet, og presenterer status på rommet på en nettside og en skjerm i vrimle. Hvert enkelt rom blir overvåket ved hjelp av en Arduino mikrokontroller (ESP8266) som er trådløst tilkoblet en server som drives av en SoC (Raspberry Pi Model B 3+). Installasjonen skal være helt autonom, ha detaljert loggføring som skal være lesbar fra en PC og en nettside som er åpent tilgjengelig for alle enheter. Driftsrammen for systemet er 1 år grunnet størrelse på database.

# Begrunnelse

Vi ønsket å lage dette prosjektet fordi vi ofte er i situasjonen at vi leter etter et ledig grupperom og ønsket oss en mulighet for å slippe å gå rundt hele vrimle eller banke på dører og forstyrre folk. Det er også fint å kunne velge det rommet med best inneklima, hvis det er flere ledige, så derfor la vi til måling av CO~2~ - nivå, temperatur og luftfuktighet. Etter forespørsel fra ledelsen (Kjetil Eide og Endre Helsem) har vi designet dette til å loggføre denne informasjonen detaljert i en SQL database så vi i tillegg har omfattende statistikk som skolen kan bruke i møte med klager fra elever og henvendeler til ansvarlige for bygget.

Vi anså også dette som en fin mulighet til å kombinere flere forskjellige typer programmering, "mekking" og designing for å skape et komplett produkt. Derfor ønsket vi også å lage et system som er tilpasset bruk i *alle* rommene på skolen samtidig, i motsetning til et system som bare fungerer i ett enkelt rom om gangen.

Ut av prosjektet sitter vi tilsammen igjen med en sammensetning av kunnskap om 3D-modellering og printing, lodding, kabling, flashing av fastvare, bruk av UNIX-teminal (zsh) og koding innen både Arduino/C, Python, SQL, HTML, CSS og Markdown. Dette vil vi ha mye glede av ved senere prosjekt, f.eks IoT opplegg hjemme, på universitetet til både prototyping innen ingeniørfeltet og fag som [MAT-INF1100](https://www.uio.no/studier/emner/matnat/math/MAT-INF1100/index.html) og [IN1900](https://www.uio.no/studier/emner/matnat/ifi/IN1900/index.html) og hvilke som helst andre prosjekt som innebærer programmering. Viktigst av alt er derimot erfaringen med å planlegge et prosjekt, fordele oppgaver, lære seg forutsetningene, og til slutt gjennomføre et prosjekt fra A til Å uten store forhåndskunnskaper, som en gruppe.



# Kompetansemål

## Teknologi og forskningslære 1

### Den unge ingeniøren

Mål for opplæringen er at eleven skal kunne

- **planlegge og bygge en konstruksjon som er fast eller bevegelig, og som har en definert funksjon (høy)**
- **bruke tredimensjonale tegninger eller skisser i utvikling av konstruksjoner (høy)**
- bruke forskjellige materialer og former for sammenføyninger og begrunne valg av materialer og byggemåte ut fra materialenes egenskaper og konstruksjonens funksjon
- **bruke sensorer og styringssystemer i forbindelse med forsøk og konstruksjoner (høy)**
- **dokumentere og vurdere konstruksjoners fysiske egenskaper og funksjonalitet ved hjelp av målinger og enkle beregninger (høy)**

### Den unge forskeren

Mål for opplæringen er at eleven skal kunne

- gjøre rede for hvordan et naturvitenskapelig prosjekt planlegges, gjennomføres og etterarbeides før det blir publisert (under prosses)
- **planlegge, gjennomføre, analysere og dokumentere systematiske målinger om støy, luftforurensning, inneklima og vannkvalitet, og drøfte virkninger på helse og miljø (høy)**

### Teknologi, naturvitenskap og samfunn

Mål for opplæringen er at eleven skal kunne

- drøfte etiske, miljømessige, kulturelle og politiske sider ved teknologisk utvikling
- **beskrive den historiske utviklingen av en teknologisk innretning, forklare virkemåten og drøfte anvendelser i samfunnet (middels)**
- gjøre rede for utvikling og produksjon av et teknologisk produkt og vurdere produktets brukervennlighet, utviklingsmuligheter og miljøpåvirkning
- beskrive prinsipper og virkemåte for noen moderne instrumenter i industri, helsevesen eller forskning, og gjøre rede for nytten og eventuelle skadevirkninger
- kartlegge og presentere praktisk bruk av realfag i en lokal bedrift eller institusjon

### Design og produktutvikling

Mål for opplæringen er at eleven skal kunne

- **gjøre rede for funksjonen til vanlige komponenter i elektroniske kretser, og gjenkjenne komponentene i en krets (høy )**
- **lage elektroniske kretser ved å lodde komponenter og simulere og teste kretsene (høy)**
- **forme og utvikle produkter som har en definert funksjon og inneholder elektronikk (høy)**
- **dokumentere og presentere designprosesser fra idé til ferdig produkt (høy)**
- begrunne valg av materialer i produkter og vurdere produktenes form og funksjon, miljømessige konsekvenser, estetikk og forbedringsmuligheter
- **utføre målinger med eller teste et eget produkt, og vurdere kvaliteten på produktet med tanke på funksjonalitet (høy)**



# Beskrivelse av funksjonalitet til deler

## Hvordan en NDIR CO~2~ sensor fungerer

Alle molekyler har sitt unike absorpsjonsspekter, hvor enkelte bølgelengder blir absorbert og skutt ut i alle retninger. Når molekylet tar imot en bestemt bølgelengde vil elektronene flytte seg til et annet energinivå. Når de går tilbake skytes et foton med den samme bølgelengden ut i en tilfeldig retning. CO2 kan ta imot og sende ut bølgelengder på 4.26 µm, 2.7 µm og 13 µm fra det infrarøde spekteret. NDIR sin CO2 sensor bruker en liten IR-lampe med bølgelengde på rundt 4,2 µm som lyser gjennom et rør med lufta i rommet. CO2-molekylene absorberer da bølgelengdene på 4.26 µm, mens de andre bølgelengdene går videre. I enden av røret er den et optisk filter som tar opp alle fotonene. Bak der er det en IR-detektor som ser alle punktene hvor bølgelengder på 4.26 µm ikke har truffet. Mengden CO2 molekyler er proporsjonal med antall “hull” det er eller antall fotoner som ikke kom videre.

## Hvordan en PIR sensor fungerer

![img](vedlegg/pirsensorillustrasjon.png)

Her er en tegning av hvordan man kobler til en PIR sensor (spenningen til den konstante 5 volten ). En PIR sensor blir brukt til å registrere bevegelse i et rom og den kan bare registrere verdiene “HIGH” eller “LOW” altså, bevegelse eller ikke bevegelse. Den merker bevegelse ved å måle differansen mellom den infrarøde strålingene som kommer fra objekter. Altså en person kan så stille rett foran den uten av den vil bli “HIGH” men så fort den personen beveger seg vil den registrere det og bli “HIGH”.(PIR=passive infrared radiation). Bilder under er selve komponenten som registrerer den infrarøde strålingen.

![img](vedlegg/pirsensorbilde.png)

![img](vedlegg/pirsensorbilde2.png)

PIR sensorer har to forskjellige potmetere under. Den ene kontrollerer rekkevidden på sensoren fra 3 til 7 meter mens den andre kontrollerer hvor stor ventetiden er til den neste avlesningen starter, mellom 0.3 sekunder til 5 min. Det stikker også ut 3 forskjellige pins på baksiden med en jumper som forbinder 2 av dem. dette gjør som et det blir 2 forskjellige innstillinger. Den ene heter "non-repeatable trigger" og gjør at når verdien er “high” og ventetiden er over vil den automatisk sette verdien til “LOW” og søke etter bevegelse igjen. Den andre heter“repeatable trigger”og holder verdien på “HIGH” helt til den merker en forandring.

# Original tidsplan

**Arbeidet ble inndelt i praktisk arbeid med sensoren, og infrastruktur rundt, og oppgavene gitt til henholdsvis Magnus og Arvin, og Martin og Ferdinand**

## Uke 5

- Finne en løsning til hva slags sensor vi kan bruke og om vi kan bruke flere forskjellige
- Kommunikasjon mellom arduinoer med NRF module

## Uke 6

- Teste forskjellige sensorer og se hva som passer best
- IR signal gjennom NRF sender (hvis ikke ble ferdig uke 5)

## Uke 7

- Lage koder og få en forståelse av hvordan sensorene fungerer
- Logge signaler mottatt via udp i en sql database
- Kanskje prøve å motta signaler fra ir-sensor

## Uke 8

- Koble til en pauseknapp til PIR sensoren  
- Lese av informasjon fra sql database og vise det på en nettside

## Uke 10

- Sette opp alt dette med en Doit ESP32
- Reservere grupperom ved hjelp av manuell innsending av reservasjon som logges i sql database

## Uke 11

- Lage case til sensoren
- Sette opp en raspberry pi med alt dette

## Uke 12

- Finne passende plassering av sensor
- Sette opp strømforsyning
- Koble opp alle arduinoene vi har lagd hittil til raspberry pi og fullføre demo-fasen av prosjektet

## Utover året

- Vise fungerende demo-prosjekt til ledelsen og få sponset resterende og hittil brukte deler
- Publisere nettsiden så den er åpent tilgjengelig
- Legge inn nettsiden som link i Canvas
- Åpne for reservasjon via identifisering av Feide for lærere
- Bruke sql databasen til å ha statistikk over luftkvalitet i grupperom, gjennomsnittlig tidsrom i bruk, gjennomsnittlig antall personer i grupperom osv.

# Logg

## Uke 5

- Valgt prosjekt
- Delt inn i grupper
- Delt inn i grupper (Arvin og Magnus på sensor, Martin og Ferdinand på sentral)
- Fant ut av at vi burde bruke en PIR sensor som hoved sensoren, men vi kan også bruke andre som ultrasonisk og C02 måler
- Bestilt flere ESP8266 til prosjektet og diverse sensorer vi kanskje kan ha bruk for. (Skjermbilde 1-2)

## Uke 6

- Funnet riktige drivere til brettene (Heltec Wifi Kit 8 og Doit ESP32)
- Testet begge brettene
- Laget klient
- Testet med knapp
- Sendt knappetrykk via UDP til server på macen
- Testa PIR sensoren og den ultrasonisk sensoren
- Lagde en kode til PIR sensoren som fungerer greit men er en del bugs og noen justeringer må til. prøver også å integrere en knapp

## Uke 7

- Lært oss SQL som dekker behovet for prosjektet
- Koblet opp IR sensor til ESP32en og sendt signalene fra den til “PacketSender” på Macen
- Lagde en PIR sensor kode som grei til prosjektet

## Uke 8

- Laget python kode som kontinuerlig kan logge informasjon fra Arduino (via UDP ved hjelp av "Socket" biblioteket) inn i en SQL database (ved bruk av "SQLite3" biblioteket) (kode 3)
- Kan lese informasjon fra SQL database og vise det i Python i både tekstform og med grafer. (skjermbilde 4)
- Vi fikser og justerer på PIR sensor koden sånn at den skal fungere etter hvordan vi vil ha den

## Uke 9

- Satt opp et mye mer robust system med postgresql database og laget en ny Python kode fra bunnen av tilpasset dette databasesystemet ved bruk av psycopg2 biblioteket og som kan motta og loggføre flere parametre (co2ppm, tempc, humidity, irsensor) (kode 5)

## Uke 10

- Valgte Autodesk Fusion 360 til 3D modellering ettersom det skal være det mest intuitivet i bruk av de profesjonelle programmene og er gratis for studenter.
- Begynte med 3D modellering (illustrasjon 6-8)
- Laget 3D modell til PIR sensor som passer oppå dekselet til ESP8266 (illustrasjon 9-11)
- Laget 3D modell til Raspberry Pi 3 B+ (illustrasjon 12-14)
- Og printet første prototype til deksel til ESP8266 som nesten passer. (illustrasjon 15-17 og bilde 18-19)
- Fått 5stk. ESP8266 i posten
- Forsøkt å sette opp disse med samme kode som ESP32, men den har ingen støtte for WPA2-Enterprise PEAP kryptering på WiFI, og kan derfor ikke kobles til "Akademiet" nettverket.

## Uke 11

- Justert 3D modell til ESP8266 så den passer perfekt og printet denne. (illustrasjon 20-21, bilde 22-24)
- Laget HTML fil til nettsiden
- Utforsket mulighetene til å bruke beautifulsoup4 biblioteket til Python til å oppdatere nettsiden så vi slipper å bruke PHP og JavaScript.
- Satt opp en ESP8266 med samme kode som ESP32en, koblet opp mot nettverk som benytter seg av vanlig WPA2 kryptering.

## Uke 12

- Tok kontakt med IT om forespørsel om å sette opp et nettverk med WPA2 kryptering på skolen, evt gi tilgang til AkaAirplay nettverket, de sa de skulle se på det.
- Printet første forsøk på deksel til Raspberry Pi 3 B+, det ble ikke helt velllykket. (bilde 21-22)
- Magnus lagde et annet design til deksel til Arduino og PIR-sensor kombinert og hull til knapp, printen ble ikke helt vellykket. (illustrasjon 23-24, bilde 25-26)
  - Verbatim Magnus: *"Pinnene som PIR-sensoren skulle sitte i var en-to millimeter for nære hverandre noe som gjorde at man måtte tvinge sensoren på. Dette fikk den til å sitte godt fast, men pinnene knakk. Skruehullene fikk jeg ikke testa da Arduinoen ikke passet. Dette er fordi plasten mulig krymper da den smeltede plasten stivner og kjøles ned. USB-hullet er også feilplassert og står på feil side av arduinoen. (porten er over brettet, mens hullet er under). skruehullene for veggfestet er 5mm, en tilfeldig verdi da vi ikke hadde bestemt oss på noen skruer. Det er mulig teip og lim er bedre. Casen har ikke noe lokk. Dette er av design og gruppa vår sin nye teknologi gjør det mulig å bruke veggen som et lokk, noe som også reduserer plastikkforbruk om du vil. Dette gjør den sterkere og mindre avansert. De to beste måtene å lage et lokk på er en glider, noe som vil være vanskelig med så små dimensjoner, ettersom veggene er 2mm og blir mye svakere om vi skjærer skinner i den. Den andre løsningen er å lage et lokk med skruehull så skrua går gjennom casen, inn i lokket, for så å gå inn i veggen. Dette skaper litt ekstra høyde, og har egentlig ingen positive sider. Vi har mye som må forbedres av denne prototypen, men lokkdesignet vårt er patentverdig."*

## Uke 13

- Skulle flytte over alle kode fra Arduino Genuino Uno til ESP8266, en fikk problemer med drivere, men fant en [løsning](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver?fbclid=IwAR3GZpZaK2d5c-Y8Lw_fUGdoAh4YidZZddZX-p-rlOhaJKi43Z6GHsxx_U8). Måtte også få USB til Serial ved hjelp av [denne](<https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers?fbclid=IwAR2heKSBZxpx_mzag608V-vMJZTuRtM7cBcGZOtHfb_ZwdxsjpcSBxjjaA8>).

- Fant [documentation](<https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html>) til Arduino Core til ESP8266 og forklaring på funksjoner for å kunne sette opp dette med UDP igjen.
- Martin har fullført en prototype av nettsiden med fungerende python-basert oppdaterer (kode 27-31)

# Vedlegg

## Skjermbilde 1

![Innkjøp av sensorer](vedlegg/skjermbildealiexpress1.png)

## Skjermbilde 2

![Innkjøp av ESP8266](vedlegg/skjermbildealiexpress2.png)

## Kode 3

### luftkvalitetssender.pde

------

```C
  /*
   * Denne koden leser av PPM verdier for luftforurensning fra en MQ135 gasssensor, viser dette på en LCD skjerm og sender informasjonen over UDP
   */
  // --- Oppsett til WiFi ---
  #include <WiFi.h>
  #include "esp_wpa2.h" //wpa2 library for å koble til bedriftsnettverk
  #include <WiFiUdp.h>
  #define EAP_IDENTITY "****" // Brukernavnet ditt med 3 bokstaver fra for og etternavn og et 2-sifret tall
  #define EAP_PASSWORD "****" //Passordet

  // --- LCD skjerm konfigurasjon ---
  //#include <LiquidCrystal_I2C.h>
  //LiquidCrystal_I2C lcd(0x27,16,2);
  // --- Luftkvalitssensor ---
  int sensor_avlesning;
  int gammelVerdi = 0;


  // --- WiFi nettverk brukernavn og passord ---
  const char * ssid = "Akademiet";
  const char * networkUsnm = "****"; //Samme brukernavn
  const char * networkPswd = "****"; //Samme passord

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
    */  udp.beginPacket(udpAddress,udpPort);
      udp.printf("Verdi:",avlesning);/*
      while (digitalRead(sensorPin) != gammelVerdi){
        udp.beginPacket(udpAddress,udpPort);
        udp.printf("%d",sensor_avlesning);
        udp.endPacket();
        Serial.println(sensor_avlesning);
        gammelVerdi = digitalRead(sensorPin);

    }
    */
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("ArQ=");
    lcd.print(sensor_avlesning,DEC);
    lcd.print(" PPM");
    lcd.println("       ");
    lcd.print("  ");
    delay(100);        /*     
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
```

### luftkvalitetslogger.py

------

```python
import socket
import sqlite3
import time
from datetime import datetime
import matplotlib.pyplot as plt
import os

filnummer = 0
if os.path.exists('luftkvalitetslogg.db') or os.path.exists('luftkvalitetslogg'+str(filnummer)+'.db'):
    filnummer += 1
    conn = sqlite3.connect('luftkvalitetslogg'+str(filnummer)+'.db')
    time.sleep(1)
    c = conn.cursor()
    if os.stat('luftkvalitetslogg' + str(filnummer) + '.db').st_size == 0:
        c.execute('CREATE TABLE grupperom(ID INTEGER PRIMARY KEY, time TEXT, airquality INTEGER, irsensor INTEGER)')
else:
    conn = sqlite3.connect('luftkvalitetslogg.db')
    c = conn.cursor()

UDP_IP = "10.25.10.63"
UDP_PORT = 16969

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))
c.execute('SELECT MAX(ID) as Nyeste FROM grupperom')

id_test = c.fetchone()[0]
if type(id_test) != int:
    id = 0
else:
    id = id_test

log = []
counter = 0

while counter < 100:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    data = int(data)
    tid = str(datetime.now())
    id += 1
    info = [(id, tid, data, 1)]
    c.executemany('''INSERT INTO grupperom VALUES(?,?,?,?)''', info)
    c.execute('SELECT * FROM grupperom ORDER BY id DESC LIMIT 1')
    conn.commit()
    print(c.fetchone())
    time.sleep(0.1)
    counter += 1

for row in c.execute('SELECT * FROM grupperom ORDER BY id DESC LIMIT 100'):
    log += c.fetchall()
x_verdi = [x[1] for x in log]
y_verdi = [x[2] for x in log]
plt.plot(x_verdi,y_verdi)
plt.show()
```

## Skjermbilde 4

![Graf over luftkvalitet](vedlegg/grafoverluftkvalitet.png)

## Kode 5

------

### rom.ini

```ini
[postgresql]
host=localhost
database=rom
user=fersch
password=Akademiet
```

### config.py

```python
from configparser import ConfigParser

def config(filename='rom.ini', section='postgresql'):
    # create a parser
    parser = ConfigParser()
    # read config file
    parser.read(filename)

    # get section, default to postgresql
    db = {}
    if parser.has_section(section):
        params = parser.items(section)
        for param in params:
            db[param[0]] = param[1]
    else:
        raise Exception('Section {0} not found in the {1} file'.format(section, filename))

    return db
```

### postgresinsert.py

```python
import psycopg2
from psycopg2 import sql
from config import config
import socket
from datetime import datetime as date

UDP_IP = "10.25.10.163"
UDP_PORT = 16969
sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
data = str(data)
data = data[2:len(data)-1]
data = data.split(",")
rom_id = data[0]
rom_id = str(rom_id)
romnavn = "rom"+rom_id
print(romnavn)

def insert(romnummer, co2ppm,tempc,humidity,irsensor):
    """ Connect to the PostgreSQL database server """
    conn = None
    try:
        # read connection parameters
        params = config()
        # connect to the PostgreSQL server
        print('Connecting to the PostgreSQL database...')
        conn = psycopg2.connect(**params)

        # create a cursor
        cur = conn.cursor()

        # execute a statement
        print('PostgreSQL database version:')
        cur.execute('SELECT version()')
        # display the PostgreSQL database server version
        db_version = cur.fetchone()
        print(db_version)

        # close the communication with the PostgreSQL
    except (Exception, psycopg2.DatabaseError) as error:
        print(error)
    finally:
        if conn is not None:
            cur.execute(sql.SQL('''SELECT MAX(ID) FROM {}''').format(sql.Identifier(romnummer)))
            id_test = cur.fetchone()[0]
            if type(id_test) != int:
                id = 1
            else:
                id = id_test+1
            print('Database connection is opened.')

            datetime = str(date.now())
            info = [(id,datetime,co2ppm,tempc,humidity,irsensor)]
            cur.executemany(sql.SQL('''INSERT INTO {} VALUES(%s, %s, %s, %s, %s, %s)''').format(sql.Identifier(romnummer)), info)
            cur.execute(sql.SQL('''SELECT * FROM rom1 ORDER BY id DESC LIMIT 1'''))
            print(type(cur.fetchone()))
            conn.commit()

if __name__ == '__main__':
    insert(romnavn, data[1],data[2],data[3],data[4])
```

## Illustrasjon 6-8

![Førsteutkast Arduino](vedlegg/forsteutkastarduino.png)

![Førsteutkast Cover](vedlegg/forsteutkastcover.png)

![Førsteutkast IR-sensor](vedlegg/forsteutkastirsensor.png)

## Illustrasjon 9-11

![Arduino med IR-sensor med cover](vedlegg/arduinomedirsensormedcover.png)

![Arduino med IR-sensor nedenfra](vedlegg/arduinomedirsensornedenfra.png)

![Arduino med IR-sensor ovenfra](vedlegg/arduinomedirsensorovenfra.png)

## Illustrasjon 12-14

![Raspberry Pi B 3+ cover](vedlegg/rbpi3bcover.png)

![Raspberry Pi B 3+ med cover](vedlegg/rbpi3bmedcover.png)

![Raspberry Pi B 3+ uten cover](vedlegg/rbpi3utencover.png)

## Illustrasjon 15-17

![Første print Arduino](vedlegg/forsteprintarduino.png)

![Første print hele](vedlegg/forsteprinthele.png)

![Første print IR-sensor](vedlegg/forsteprintirsensor.png)

## Bilde 18-20

![Første fungerende print ovenfra med støtte](vedlegg/vedlegg16.jpg "ovenfra med støtte")

![Første fungerende print fra siden](vedlegg/vedlegg17.jpg "fra siden")

![Første fungerende print i profil](vedlegg/vedlegg18.jpg "i profil")

## Bilde 21-22

![](vedlegg/rbpi3bforsteprintforsokforfra.jpg)

![rbpi3bforsteprintforsokovenfra](vedlegg/rbpi3bforsteprintforsokovenfra.jpg)

## Illustrasjon 23-24

![img](vedlegg/pirsensorcovermagnusovenfraprint.png)

![img](vedlegg/pirsensorcovermagnusnedenfraprint.png)

## Bilde 25-26

![img](vedlegg/pirsensorcovermagnusovenfra.jpg)

![img](vedlegg/pirsensorcovermagnusnedenfra.jpg)

## Kode 27-31

### htmlOppdaterer.py

---

```python
import oppdaterLib as erstatt

tuple = {"romNr":"217","luftKval":"100","status":"0"}    #får en touple med verdiene (romnummer, co2ppm, pir-sensor)
if tuple["status"]=="0":
    status = "Ledig"
else:
    status = "Opptatt"

luft_kval = int(tuple["luftKval"])
if luft_kval > 900:
    luft = "Lav"
elif luft_kval <= 900 and luft_kval >= 700:
    luft = "Middels"
else:
    luft = "Høy"

erstatt.luftHtml("grupperom.html",tuple["romNr"], luft_kval, luft)
erstatt.statusHtml("grupperom.html", tuple["romNr"], status)
```

### oppdatererLib.py

---

```python
#oppdatere status:
def statusHtml(htmlFil, romnummer, status):
    parser = "html5lib"  # bruker html5lib som parser

    from bs4 import BeautifulSoup
    with open(htmlFil) as fp:
        soup = BeautifulSoup(fp, parser)  # åpner filen

    id = (romnummer + "status")  # lager en id til luftkvalitet
    # oppdatere luftkvaliteten til rommet:
    tag = soup.find(id=id)  # finner taggen som stemmer med luft-id-en
    tag.string.replace_with(status)  # erstatter strengen til taggen med ny verdi

    with open(htmlFil, "w") as outf:
        outf.write(str(soup))  # overskriver det gamle dokumentet med det nye lagd i python
#Oppdatere luftkvalitet:
def luftHtml(htmlFil, romnummer, co2ppm,luftkval):
    parser = "html5lib"

    from bs4 import BeautifulSoup
    with open(htmlFil) as fp:
        soup = BeautifulSoup(fp, parser)  # åpner filen

    id = (romnummer + "luft")
    tag = soup.find(id = id)  # finner taggen som stemmer med luft-id-en


    tag.attrs = {'id': id, 'title': [co2ppm], "name": [co2ppm]}
    tag.string.replace_with(luftkval)

    with open(htmlFil, "w") as outf:
        outf.write(str(soup))```
```

### grupperomOversikt.html
```HTML
<!DOCTYPE html>
<html>

<head>
  <meta content="width=device-width, initial-scale=1.0" name="viewport" />
  <link rel="stylesheet" type="text/css" href="grupperomOversikt.css">
</head>

<body>
  <!-- Meny -->
  <div class="menu">
    <ul>
      <li class="active" id="over" onclick="side(1)">Oversikt</li>
      <li class="inactive" id="kartm" onclick="side(2)">Kart</li>
      <li class="inactive" id="hjelp" onclick="side(3)">Hjelp</li>
      <li class="inactive" id="pro" onclick="side(4)">Om Prosjektet</li>
      <li class="inactive" id="canvas" onclick="window.location.href = 'https://akademiet.instructure.com';">Canvas</li>
      <p id="easteregg1" ondblclick="alert('01110000 01101100 01100001 01100011 01100101 01101000 01101111 01101100 01100100 01100101 01110010')">Påskeegg?</p>
    </ul>
  </div>

  <!-- Oversikt -->
  <div class="innhold" id="Oversikt">
    <h1>Oversikt over grupperom</h1>
    <table id="myTable">
      <thead id="Tabell">
        <tr>
          <th class="button" id="etasje" onclick="sortTable(0)" title="Sorter etter etasje">Etasje</th>
          <th class="button" id="romnummer" onclick="sortTable(1)" title="Sorter etter romnummer">Romnr.</th>
          <th class="button" id="navn" onclick="sortTable(2)" title="Sorter etter romnavn">Navn</th>
          <th class="button" onclick="sortTable(3)" title="Sorter etter status">Status</th>
          <th class="button" id="luftkvalitet" onclick="sortTableLuft(4)" title="Sorter etter luftkvalitet">Luftkvalitet</th>
        </tr>
      </thead>

      <tbody>
        <tr id="111" class="tabell">
          <td id="etasje">1</td>
          <td>111</td>
          <td id="navn">Kahlo</td>
          <td id="111status">Ledig</td>
          <td id="111luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="112" class="tabell">
          <td id="etasje">1</td>
          <td>112</td>
          <td id="navn">Bergman</td>
          <td id="112status">Ledig</td>
          <td id="112luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="113" class="tabell">
          <td id="etasje">1</td>
          <td>113</td>
          <td id="navn">Kafka</td>
          <td id="113status">Ledig</td>
          <td id="113luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="114" class="tabell">
          <td id="etasje">1</td>
          <td>114</td>
          <td id="navn">Kurosawa</td>
          <td id="114status">Ledig</td>
          <td id="114luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="115" class="tabell">
          <td id="etasje">1</td>
          <td>115</td>
          <td id="navn">Hemingway</td>
          <td id="115status">Ledig</td>
          <td id="115luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="209" class="tabell">
          <td id="etasje">2</td>
          <td>209</td>
          <td id="navn">Ullmann</td>
          <td id="209status">Ledig</td>
          <td id="209luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="210" class="tabell">
          <td id="etasje">2</td>
          <td>210</td>
          <td id="navn">Dahl</td>
          <td id="210status">Ledig</td>
          <td id="210luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="211" class="tabell">
          <td id="etasje">2</td>
          <td>211</td>
          <td id="navn">Hepburn</td>
          <td id="211status">Ledig</td>
          <td id="211luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="212" class="tabell">
          <td id="etasje">2</td>
          <td>212</td>
          <td id="navn">Streep</td>
          <td id="212status">Ledig</td>
          <td id="212luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="213" class="tabell">
          <td id="etasje">2</td>
          <td>213</td>
          <td id="navn">Welles</td>
          <td id="213status">Ledig</td>
          <td id="213luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="214" class="tabell">
          <td id="etasje">2</td>
          <td>214</td>
          <td id="navn">Shelley</td>
          <td id="214status">Ledig</td>
          <td id="214luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="215" class="tabell">
          <td id="etasje">2</td>
          <td>215</td>
          <td id="navn">Scorsese</td>
          <td id="215status">Ledig</td>
          <td id="215luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="216" class="tabell">
          <td id="etasje">2</td>
          <td>216</td>
          <td id="navn">Lee</td>
          <td id="216status">Ledig</td>
          <td id="216luft" name="100" title="100">Høy</td>
        </tr>
        <tr id="217" class="tabell">
          <td id="etasje">2</td>
          <td>217</td>
          <td id="navn">Leone</td>
          <td id="217status">Ledig</td>
          <td id="217luft" name="100" title="100">Høy</td>
        </tr>
      </tbody>
    </table>
  </div>

  <div id="kart">
    <div id="Vrimle" class="unclick">
      <p id="Vrimle">Vrimle</p>
    </div>
    <div id="etasje1" class="unclick" onmouseover="hover('etasje1', 'etasje2')" onmouseout="hoverNot()">
      <div id="111K" name="grupperom" class="111">
        <div>111</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Høy</td>
          </tr>
        </table>
      </div>
      <div id="112K" name="grupperom" class="200">
        <div>112</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Lav</td>
          </tr>
        </table>
      </div>
      <div id="113K" name="grupperom" class="700">
        <div>113</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Middels</td>
          </tr>
        </table>
      </div>
      <div id="114K" name="grupperom" class="500">
        <div>114</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Høy</td>
          </tr>
        </table>
      </div>
      <div id="115K" name="grupperom" class="800">
        <div>115</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Høy</td>
          </tr>
        </table>
      </div>
    </div>
    <div id="etasje2" class="unclick" onmouseover="hover('etasje2', 'etasje1')" onmouseout="hoverNot()">
      <div id="209K" name="grupperom" class="111">
        <div>209</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Lav</td>
          </tr>
        </table>
      </div>
      <div id="210K" name="grupperom" class="1000">
        <div>210</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Lav</td>
          </tr>
        </table>
      </div>
      <div id="211K" name="grupperom" class="111">
        <div>211</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Lav</td>
          </tr>
        </table>
      </div>
      <div id="212K" name="grupperom" class="600">
        <div>212</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Høy</td>
          </tr>
        </table>
      </div>
      <div id="213K" name="grupperom" class="800">
        <div>213</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Middels</td>
          </tr>
        </table>
      </div>
      <div id="214K" name="grupperom" class="500">
        <div>214</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Høy</td>
          </tr>
        </table>
      </div>
      <div id="215K" name="grupperom" class="111">
        <div>215</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Middels</td>
          </tr>
        </table>
      </div>
      <div id="216K" name="grupperom" class="700">
        <div>216</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Ledig</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Middels</td>
          </tr>
        </table>
      </div>
      <div id="217K" name="grupperom" class="111">
        <div>217</div>
        <table>
          <tr>
            <td>Status:</td>
            <td>Opptatt</td>
          </tr>
          <tr>
            <td>Luftkvalitet:</td>
            <td>Lav</td>
          </tr>
        </table>
      </div>
    </div>
  </div>
  <!-- Om Prosjektet: -->
  <div class="innhold" id="omP" name="annet">
    <h1>Om Prosjektet</h1>
    <p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut
      aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum
      zzril delenit augue duis dolore te feugait nulla facilisi.</p>
  </div>

  <!-- Hjelp -->
  <div class="innhold" id="trengerHjelp" name="annet">
    <h1>Hjelp</h1>
    <p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut
      aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum
      zzril delenit augue duis dolore te feugait nulla facilisi.</p>
  </div>
  <script src="grupperomOversikt.js" type="text/javascript"></script>
    </body>
</html>
```

### oversiktGrupperom.css

```css

:root {
  --primCol: #F9F8F6;
  --secCol: #EbE9E8;
  --hoverCol: #FFBA66;
  --paddingWide: 10%;
  --paddingSmall: 5%;
}

/* Meny */
ul {
  padding: 0;
  padding-left: var(--paddingWide);
  margin: 0;
  list-style-type: none;
  overflow: hidden;
  background-color: var(--secCol);
}

li {
  display: block;
  text-align: left;
  text-align: center;
  text-decoration: none;
  float: left;
  display: block;
  padding: 20px;
}

li:hover {
  background-color: var(--hoverCol);
}

* {
  box-sizing: border-box;
}
}

.menu {
  position: fixed;
  top: 0;
  width: 100%;
  left: 0;
}

.active {
  background-color: var(--primCol);
}

.inactive {
  background-color: var(--secCol);
  cursor: pointer;
}

.active:hover {
  background-color: var(--primCol);
}

/* Oversikt */
table#myTable {
  border-collapse: collapse;
  text-align: center;
  margin-left: 0;
  width: 100%;
}

th {
  text-align: center;
  color: white;
  background-color: #E77731;
  margin: 10px;
  padding: 10px;
  letter-spacing: 2px;
  width: 20%;
  cursor: pointer;
  transition: 0.48s;
  border: solid var(--primCol) 3px;
}

th:hover {
  background-color: orange;
  transition: 0.5s;
  transform: scale(1.01);
}

tr.tabell {
  transition: 0.2s;
  background-color: var(--secCol);
}

tr.tabell:hover {
  background-color: var(--hoverCol);
  transition: 0.2s;
}

tr.tabell>td {
  padding: 5px;
  border-left: solid var(--primCol) 3px;
}

/*Kart*/
div#kart {
  width: 70vw;
  height: 80vh;
  position: relative;
  margin: auto;
  top: 20px;
  text-align: center;
  display: none;
  max-width: 700px;
}

div.unclick {
  position: absolute;
  width: 29%;
}

div.unclick:hover {
  width: 35%;
  position: absolute;
  transition: 0.3s;
}

div#etasje2 {
  right: 0;
  height: 100%
}

div#etasje1 {
  left: 40%;
  height: 100%;
}

[name="grupperom"] {
  height: 11.1%;
  transition: 0.3s;
  background-color: #EbE9E8;
  position: relative;
}

[name="grupperom"]:hover {
  transform: scale(1.01);
  transition: 0.1s;
  font-size: 0.9em;
  padding: 10px;
  box-shadow: 0 0 5% rgba(0, 0, 0, 0.5);
}

[name="grupperom"]>div {
  position: absolute;
  top: 35%;
  width: 100%;
}

[name="grupperom"]>table {
  display: none;
}

[name="grupperom"]:hover>table {
  display:inline-block;
  text-align: center;
}

[name="grupperom"]:hover>div {
  display: none;
}

#Vrimle {
  background-color: #EbE9E8;
  width: 38%;
  height: 100%;
}

#Vrimle>p {
  writing-mode: vertical-rl;
  text-align: center;
  font-size: 7vh;
}

[name="grupperom"]>table {
  font-size: 2.5vw;
  text-align: left;
}

@media only screen and (min-width: 700px) {
  [name="grupperom"]>table {
    font-size: 15px;
  }
}

/* Sider som enda ikke er ferdig */
div.innhold {
  width: 100%;
  padding-left: var(--paddingWide);
  padding-right: var(--paddingWide);
}

div[name="annet"] {
  display: none;
}

/* Felles */
html {
  background-color: var(--primCol);
  font-family: sans-serif;
}

h1 {
  padding-top: 1%;
  font-family: arial;
  color: #584434;
  margin-left: 0;
  margin-bottom: 10px;
}

/*Eastereggs
easteregg1*/
@media only screen and (max-width: 1000px) {
  #easteregg1 {
    display: none;
  }
}

#easteregg1 {
  color: var(--secCol);
  cursor: help;
}

/*Mindre viktige elementer hjemmes når det ikke blir plass til dem*/
@media only screen and (max-width: 600px) {
  #etasje {
    display: none;
  }

  li {
    font-size: 15px;
    padding: 15px;
  }
}

@media only screen and (max-width: 520px) {
  #navn {
    display: none;
  }

  div.innhold {
    width: 100%;
    padding-left: var(--paddingSmall);
    padding-right: var(--paddingSmall);
  }

  div#Kart {
    margin-left: 5%;
  }

  ul {
    padding-left: var(--paddingSmall);
  }
}

@media only screen and (max-width: 450px) {
  h1 {
    font-size: 25px;
  }
}

@media only screen and (max-width: 460px) {
  #pro {
    display: none;
  }
}

@media only screen and (max-width: 335px) {
  #hjelp {
    display: none;
  }
}

@media only screen and (max-width: 325px) {
  tr.tabell td {
    font-size: 90%;
  }

  th {
    font-size: 90%;
  }
}


```

### grupperomOversikt.js

```js

// Bla mellom sidene
function side(n) {
  var a, b, c, d = 0;
  a = document.getElementById("Oversikt");
  b = document.getElementById("kart")
  c = document.getElementById("trengerHjelp");
  d = document.getElementById("omP");
  if (n == 1) {
    a.style.display = "block";
    b.style.display = "none";
    c.style.display = "none";
    d.style.display = "none";

    document.getElementById("over").className = "active";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "inactive";
  } else if (n == 2) {
    a.style.display = "none";
    b.style.display = "grid";
    c.style.display = "none";
    d.style.display = "none";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "active";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "inactive";
  } else if (n == 3) {
    a.style.display = "none";
    b.style.display = "none";
    c.style.display = "block";
    d.style.display = "none";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "active";
    document.getElementById("pro").className = "inactive";
  } else {
    a.style.display = "none";
    b.style.display = "none";
    c.style.display = "none";
    d.style.display = "block";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "active";
  }
}

// Sorter tabellen
function sortTable(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("myTable");
  switching = true;
  // Set the sorting direction to ascending:
  dir = "asc";
  /* Make a loop that will continue until
  no switching has been done: */
  while (switching) {
    // Start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /* Loop through all table rows (except the
    first, which contains table headers): */
    for (i = 1; i < (rows.length - 1); i++) {
      // Start by saying there should be no switching:
      shouldSwitch = false;
      /* Get the two elements you want to compare,
      one from current row and one from the next: */
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      /* Check if the two rows should switch place,
      based on the direction, asc or desc: */
      if (dir == "asc") {
        if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      } else if (dir == "desc") {
        if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      /* If a switch has been marked, make the switch
      and mark that a switch has been done: */
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      // Each time a switch is done, increase this count by 1:
      switchcount++;
    } else {
      /* If no switching has been done AND the direction is "asc",
      set the direction to "desc" and run the while loop again. */
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}

function sortTableLuft(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("myTable");
  switching = true;
  // Set the sorting direction to ascending:
  dir = "asc";
  /* Make a loop that will continue until
  no switching has been done: */
  while (switching) {
    // Start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /* Loop through all table rows (except the
    first, which contains table headers): */
    for (i = 1; i < (rows.length - 1); i++) {
      // Start by saying there should be no switching:
      shouldSwitch = false;
      /* Get the two elements you want to compare,
      one from current row and one from the next: */
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      /* Check if the two rows should switch place,
      based on the direction, asc or desc: */
      if (dir == "asc") {
        if (Number(x.title) > Number(y.title)) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      } else if (dir == "desc") {
        if (Number(x.title) < Number(y.title)) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      /* If a switch has been marked, make the switch
      and mark that a switch has been done: */
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      // Each time a switch is done, increase this count by 1:
      switchcount++;
    } else {
      /* If no switching has been done AND the direction is "asc",
      set the direction to "desc" and run the while loop again. */
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}

function luftStatus() {
  sortTableLuft(4);
  sortTable(3);
}
// Gi rom farge etter status:
function fargeKode(id) {
  var boks, x, y, z, p = 0;
  y = document.getElementById(id);
  x = parseInt(y.className);
  p = y.getElementsByTagName('td')[1].innerHTML;
  /*document.getElementById('button').innerHTML = p;*/
  if (p == 'Ledig') {
    if (x < 700) {
      y.style.backgroundColor = '#57bb3e';
    } else if (x < 900) {
      y.style.backgroundColor = '#FFBB00';
    } else {
      y.style.backgroundColor = '#ff7440';
    }
  }
}

function statusFarge() {
  for (var i = 0; i < 5; i++) {
    fargeKode(i + 111 + 'K');
  }
  for (var i = 0; i < 9; i++) {
    fargeKode(i + 209 + 'K');
  }
}

function hover(etasje1, etasje2) {
  var x, y = 0;
  x = document.getElementById(etasje1);
  y = document.getElementById(etasje2);
  x.style.width = '38%';
  y.style.width = '20%';
  //x.style.height = '96.6%';
}

// Etasje utvider seg onmouseover
function hoverNot() {
  var x, y = 0;
  x = document.getElementById('etasje1');
  y = document.getElementById('etasje2');
  x.style.width = '28%';
  x.style.transition = '0.3s';
  y.style.width = '30%';
  y.style.transition = '0.3s';
  y.style.height = '100%';
  x.style.height = '100%';
}

function myFunction(x) {
  if (x.matches) { // If media query matches
    document.getElementById("romnummer").innerHTML = "Romnr.";
    document.getElementById("luftkvalitet").innerHTML = "Luftkval.";
  } else {
    document.getElementById("romnummer").innerHTML = "Romnummer";
    document.getElementById("luftkvalitet").innerHTML = "Luftkvalitet";
  }
}

var x = window.matchMedia("(max-width: 700px)");
myFunction(x); // Call listener function at run time
x.addListener(myFunction); // Attach listener function on state changes
luftStatus();
statusFarge();

```
