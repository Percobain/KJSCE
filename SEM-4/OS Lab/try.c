#include <iostream> 
#include <limits> 
 
using namespace std; 
 
const int INF = numeric_limits<int>::max(); 
const int MAX = 6; 
 
void dijkstra(int v, int cost[MAX][MAX], int dist[MAX], int n) { 
    bool S[MAX] = {false}; 
 
    for (int i = 0; i < n; i++) { 
        if (cost[v][i] == 0 && i != v) 
            dist[i] = INF; 
        else 
            dist[i] = cost[v][i]; 
    } 
 
    S[v] = true; 
    dist[v] = 0; 
 
    for (int num = 1; num < n; num++) { 
        int u = -1, minDist = INF; 
 
        for (int i = 0; i < n; i++) { 
            if (!S[i] && dist[i] < minDist) { 
                minDist = dist[i]; 
                u = i; 
            } 
        } 
 
        if (u == -1) break; 
        S[u] = true; 
 
        for (int w = 0; w < n; w++) { 
            if (!S[w] && cost[u][w] != 0 && dist[u] + cost[u][w] < dist[w]) { 
                dist[w] = dist[u] + cost[u][w]; 
            } 
        } 
    } 
} 

int main() { 
    int cost[MAX][MAX] = { 
        {0, 7, 9, 0, 0, 14}, 
        {7, 0, 10, 15, 0, 0}, 
        {9, 10, 0, 11, 0, 2}, 
        {0, 15, 11, 0, 6, 0}, 
        {0, 0, 0, 6, 6, 9}, 
        {14, 0, 2, 0, 9, 0} 
    }; 
 
    int dist[MAX]; 
    int source = 0; 
 
    dijkstra(source, cost, dist, MAX); 
 
    cout << "Shortest distances from vertex " << source + 1 << ":\n"; 
    for (int i = 0; i < MAX; i++) { 
        if (dist[i] == INF) 
            cout << "To vertex " << i + 1 << ": No Path\n"; 
        else 
            cout << "To vertex " << i + 1 << ": " << dist[i] << endl; 
    } 
 
    return 0; 
}