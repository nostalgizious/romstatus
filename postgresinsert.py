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



