from insert import insert_dummy_data
from benchmark import run_benchmark
import argparse

def main():
    parser = argparse.ArgumentParser(description='B-tree vs PostgreSQL performance comparison')
    parser.add_argument('--records', type=int, default=10000, help='Number of records to insert')
    parser.add_argument('--searches', type=int, default=1000, help='Number of searches to perform')
    args = parser.parse_args()
    
    print(f"Inserting {args.records} records into the database...")
    insert_dummy_data(args.records)
    
    print(f"Running benchmark with {args.searches} searches...")
    results = run_benchmark(args.searches)
    
    print("\nResults Summary:")
    print(f"Average B-tree search time: {results['avg_btree_time']:.6f} seconds")
    print(f"Average PostgreSQL search time: {results['avg_postgres_time']:.6f} seconds")
    print(f"Speedup factor: {results['avg_postgres_time'] / results['avg_btree_time']:.2f}x")
    
    print("\nPlot saved as 'plot.png'")

if __name__ == "__main__":
    main()