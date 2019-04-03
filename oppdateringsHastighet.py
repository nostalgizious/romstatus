from htmlOppdaterer import oppdaterRom
from time import sleep

romListe = [111, 112, 113, 114, 115, 209, 210, 211, 212, 213, 214, 215, 216, 217]

for romNummer in romListe:
    if romNummer == 217:
        oppdaterRom(romNummer)
        sleep(60)
    else:
        oppdaterRom(romNummer)
