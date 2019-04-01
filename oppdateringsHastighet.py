from htmlOppdaterer import oppdaterRom
from time import sleep

romListe = [111, 112, 113, 114, 115, 209, 210, 211, 212, 213, 214, 215, 216, 217]

for romnummer in romListe:
    if romnummer == 217:
        sleep(60)
    oppdaterRom(romnummer)
