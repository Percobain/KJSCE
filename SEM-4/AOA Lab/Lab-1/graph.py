import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv('output.csv')

plt.figure(figsize=(10, 6))
plt.plot(df['n'], df['insertion'], 'r-o', label='Insertion Sort')
plt.plot(df['n'], df['selection'], 'b-o', label='Selection Sort')
plt.xlabel('Input Size (n)')
plt.ylabel('Time (milliseconds)')
plt.title('Time Complexity Comparison')
plt.legend()
plt.grid(True)
plt.savefig('OG.png')
plt.show()