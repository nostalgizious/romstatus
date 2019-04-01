import oppdaterLib as erstatt
from postgresRead import read

def oppdaterRom(romNummer):
    sisteVerdi = read(romNummer) #får en tuple med verdiene [romnummer, id, date, co2ppm, tempc, humidity, irsensor]
    romNummer = sisteVerdi[0]
    co2ppm = int(sisteVerdi[3])
    irsensor = int(sisteVerdi[6])

    if irsensor == 0:
        status = "Ledig"
    elif irsensor == 1:
        status = "Opptatt"
    elif irsensor == 2:
        status = "Booket"
    else:
        print("status input value error")

    if co2ppm > 900:
        luft = "Lav"
    elif co2ppm <= 900 and co2ppm >= 700:
        luft = "Middels"
    else:
        luft = "Høy"

    erstatt.luftHtml("grupperomOversikt.html",romNummer, str(co2ppm), luft)
    erstatt.statusHtml("grupperomOversikt.html", romNummer, status)
