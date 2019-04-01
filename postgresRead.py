import psycopg2
from psycopg2 import sql
from config import config

def read(romnummer):
    """ Connect to the PostgreSQL database server """
    conn = None
    rom = 'rom'+str(romnummer)
    try:
        # read connection parameters
        params = config()
        #print(params)
        # connect to the PostgreSQL server
        #print('Connecting to the PostgreSQL database...')
        conn = psycopg2.connect(**params)

        # create a cursor
        cur = conn.cursor()

        # execute a statement
        #print('PostgreSQL database version:')
        cur.execute('SELECT version()')
        # display the PostgreSQL database server version
        db_version = cur.fetchone()
        #print(db_version)

        # close the communication with the PostgreSQL
    except (Exception, psycopg2.DatabaseError) as error:
        print(error)
    finally:
        if conn is not None:
            cur.execute(sql.SQL('''SELECT * FROM {} ORDER BY id DESC LIMIT 1''').format(sql.Identifier(rom)))
            #id_test = cur.fetchone()[0]
            #if type(id_test) != int:
            #    id = 1
            #else:
            #    id = id_test+1
            #print('Database connection is opened.')
            avlesning = (romnummer, )+cur.fetchone()
            conn.commit()
            print(avlesning)
