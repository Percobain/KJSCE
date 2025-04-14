# load_btree.py
from btree import BTree
from db_utils import get_pg_conn

def load_btree_from_postgres():
    conn = get_pg_conn()
    cur = conn.cursor()
    cur.execute("SELECT id FROM btreedemo")
    ids = [row[0] for row in cur.fetchall()]
    conn.close()

    bt = BTree(t=3)
    for key in ids:
        bt.insert(key)

    return bt
