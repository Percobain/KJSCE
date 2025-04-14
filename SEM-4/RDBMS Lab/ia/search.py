from btree import BTree
from load_btree import load_btree_from_postgres
from db_utils import get_pg_conn
import time
import random

def search_in_btree(bt, key):
    """Search for a key in the B-tree and return the time taken"""
    start_time = time.time()
    result = bt.search(key)
    end_time = time.time()
    return (end_time - start_time), result is not None

def search_in_postgres(key):
    """Search for a key in PostgreSQL and return the time taken"""
    conn = get_pg_conn()
    cur = conn.cursor()
    
    start_time = time.time()
    cur.execute("SELECT id FROM btreedemo WHERE id = %s", (key,))
    result = cur.fetchone()
    end_time = time.time()
    
    conn.close()
    return (end_time - start_time), result is not None

def get_random_keys(num_keys, max_id):
    """Get random keys to search for"""
    return random.sample(range(1, max_id + 1), min(num_keys, max_id))