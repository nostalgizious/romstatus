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
        outf.write(str(soup))