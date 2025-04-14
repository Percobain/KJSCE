import psycopg2

def get_pg_conn():
    return psycopg2.connect(
        dbname="hospitalmanagementdb",
        user="postgres",
        password="password",
        host="localhost",
        port="5432"
    )
