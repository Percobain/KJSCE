#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define M 200000

int g[N + 1][N + 1];
int sz[N + 1];
int vis[N + 1];
int p[N + 1];
int c[N + 1];
int cs = 0;

void add(int a, int b) {
    g[a][sz[a]++] = b;
    g[b][sz[b]++] = a;
}

int dfs(int v) {
    vis[v] = 1;

    for (int i = 0; i < sz[v]; i++) {
        int u = g[v][i];

        if (!vis[u]) {
            p[u] = v;
            if (dfs(u)) return 1;
        }
        else if (u != p[v]) {
            int cur = v;
            cs = 0;
            c[cs++] = u;
            while (cur != u) {
                c[cs++] = cur;
                cur = p[cur];
            }
            c[cs++] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        sz[i] = vis[i] = 0;
        p[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i)) {
            printf("%d\n", cs);
            for (int i = 0; i < cs; i++) {
                printf("%d ", c[i]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("IMPOSSIBLE\n");
    return 0;
}


int dfs(vector<int> adj, stack<int> st, int node, vector<int> &visited) {
    visited[node] = 1;
    st.push(node);
    for (int i = 0; i < adj[node].size(); ++i) {
        if (!visited[adj[node][i]]) {
            if (dfs(adj, st, adj[node][i], visited)) {
                return 1;
            }
        } else if (st.top() == adj[node][i]) {
            cout << "YES\n";
            cout << st.size() << "\n";
            while (!st.empty()) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << "\n";
            return 1;
        }
    }

}