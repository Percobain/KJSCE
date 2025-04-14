import matplotlib.pyplot as plt
import numpy as np
from load_btree import load_btree_from_postgres
from search import search_in_btree, search_in_postgres, get_random_keys
from db_utils import get_pg_conn

def get_max_id():
    """Get the maximum ID from the database"""
    conn = get_pg_conn()
    cur = conn.cursor()
    cur.execute("SELECT MAX(id) FROM btreedemo")
    max_id = cur.fetchone()[0]
    conn.close()
    return max_id

def run_benchmark(num_searches=1000):
    """Run benchmark comparing B-tree and PostgreSQL search performance"""
    print("Loading B-tree from PostgreSQL...")
    bt = load_btree_from_postgres()
    print("B-tree loaded!")
    
    max_id = get_max_id()
    print(f"Max ID in database: {max_id}")
    
    # Generate random keys to search for
    keys = get_random_keys(num_searches, max_id)
    
    # Run benchmarks
    btree_times = []
    postgres_times = []
    
    print(f"Running {num_searches} searches...")
    
    for i, key in enumerate(keys):
        if i % 100 == 0:
            print(f"Completed {i}/{num_searches} searches")
        
        # B-tree search
        btree_time, _ = search_in_btree(bt, key)
        btree_times.append(btree_time)
        
        # PostgreSQL search
        postgres_time, _ = search_in_postgres(key)
        postgres_times.append(postgres_time)
    
    # Calculate statistics
    avg_btree_time = np.mean(btree_times)
    avg_postgres_time = np.mean(postgres_times)
    
    print(f"Average B-tree search time: {avg_btree_time:.6f} seconds")
    print(f"Average PostgreSQL search time: {avg_postgres_time:.6f} seconds")
    
    # Create a plot
    plt.figure(figsize=(10, 6))
    plt.bar(['B-tree', 'PostgreSQL'], [avg_btree_time, avg_postgres_time])
    plt.title('Average Search Time Comparison')
    plt.ylabel('Time (seconds)')
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    
    # Add values on top of bars
    for i, v in enumerate([avg_btree_time, avg_postgres_time]):
        plt.text(i, v + 0.0001, f"{v:.6f}s", ha='center')
    
    # Save the plot
    plt.tight_layout()
    plt.savefig('plot.png')
    plt.show()
    
    return {
        'btree_times': btree_times,
        'postgres_times': postgres_times,
        'avg_btree_time': avg_btree_time,
        'avg_postgres_time': avg_postgres_time
    }

if __name__ == "__main__":
    run_benchmark()