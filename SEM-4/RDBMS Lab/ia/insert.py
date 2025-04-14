import psycopg2
import random
import string

def get_pg_connection():
    return psycopg2.connect(
        dbname="hospitalmanagementdb",
        user="postgres",
        password="password",
        host="localhost",
        port="5432"
    )

def random_name():
    return ''.join(random.choices(string.ascii_letters, k=6))

def insert_dummy_data(num_records=10000):
    conn = get_pg_connection()
    cur = conn.cursor()

    # Ensure table is empty
    cur.execute("TRUNCATE TABLE btreedemo RESTART IDENTITY")

    # Generate and insert records
    records = [(i, random_name()) for i in range(1, num_records + 1)]
    cur.executemany("INSERT INTO btreedemo (id, name) VALUES (%s, %s)", records)

    conn.commit()
    conn.close()
    print(f"✅ Inserted {num_records} dummy records into btreedemo.")

if __name__ == "__main__":
    insert_dummy_data()
