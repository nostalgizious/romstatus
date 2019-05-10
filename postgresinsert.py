import psycopg2
from psycopg2 import sql
from config import config
from config import udpconfig
import socket
from datetime import datetime as date

udp = udpconfig()
print(udp)
UDP_IP = udp.get('ip')
UDP_PORT = int(udp.get('port'))
sock = socket.socket(socket.AF_INET, # Internet
            socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

for _ in range(5):
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    data = str(data)
    data = data.split(":")
    if data[0] == "romNummer":
        romnavn = "rom"+data[1]
    if else data[0] == "co2PPM":
        co2ppm = data[1]
    if else data[0] == "tempC":
        tempc = data[1]
    if else data[0] == "humidity":
        humidity = data[1]
    if else data[0] == "irSensor":
        irsensor = data[1]
    else:
        continue

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
            conn.commit()

if __name__ == '__main__':
    insert(romnavn, data[1],data[2],data[3],data[4])
