#include <bits/stdc++.h>
using namespace std;

vector<int> atkin(int n) {
    vector<int> p;
    if (n < 2) return p;
    if (n >= 2) p.push_back(2);
    if (n >= 3) p.push_back(3);

    vector<bool> s(n + 1, false);
    int m = sqrt(n);

    for (int x = 1; x <= m; x++) {
        int x2 = x * x;
        for (int y = 1; y <= m; y++) {
            int y2 = y * y;

            int k = 4 * x2 + y2;
            if (k <= n && (k % 12 == 1 || k % 12 == 5)) s[k] = !s[k];

            k = 3 * x2 + y2;
            if (k <= n && k % 12 == 7) s[k] = !s[k];

            k = 3 * x2 - y2;
            if (x > y && k <= n && k % 12 == 11) s[k] = !s[k];
        }
    }

    for (int i = 5; i <= m; i++) {
        if (s[i]) {
            int i2 = i * i;
            for (int j = i2; j <= n; j += i2) s[j] = false;
        }
    }

    for (int i = 5; i <= n; i++) if (s[i]) p.push_back(i);
    return p;
}

int main() {
    int n; 
    cin >> n;
    for (int x : atkin(n)) cout << x << " ";
    cout << "\n";
}