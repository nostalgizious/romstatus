import psycopg2
from psycopg2 import sql
from config import config
#from oppdateringsHastighet import romListen
romListe = [111, 112, 113, 114, 115, 209, 210, 211, 212, 213, 214, 215, 216, 217]

""" Connect to the PostgreSQL database server """
conn = None
try:
    # read connection parameters
    params = config()
    print(params)
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
except (Exception, psycopg2.DatabaseError) as error:
    print(error)
finally:
    if conn is not None:
        for romNummer in romListe:
            rom = 'rom'+str(romNummer)
            cur.execute("SELECT EXISTS(SELECT * FROM information_schema.tables WHERE table_name=%s)", ('rom',))
            if bool(cur.rowcount) == True:
                 cur.execute(sql.SQL('''CREATE TABLE {}(ID INTEGER PRIMARY KEY, datetime TEXT, co2ppm INTEGER, tempc FLOAT, humidity FLOAT, irsensor INTEGER)''').format(sql.Identifier(rom)))
                 print('created table '+rom)
                 conn.commit()
            else:
                continue
