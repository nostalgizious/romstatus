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