#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, cacheSize;
    cout << "Enter the number of values: ";
    cin >> n;

    cout << "Enter cache size: ";
    cin >> cacheSize;

    vector<int> pages(n);
    cout << "Enter reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    deque<int> cache;
    int hit = 0;

    for (int page : pages) {
        if (find(cache.begin(), cache.end(), page) != cache.end()) {
            hit++;
            cache.erase(remove(cache.begin(), cache.end(), page), cache.end());
        } else {
            if (cache.size() == cacheSize) {
                cache.pop_front();
            }
        }
        cache.push_back(page);
        cout << "Cache: ";
        for (int p : cache) {
            cout << p << " ";
        }
        cout << endl;
    }

    double hitRatio = (double)hit / n;
    cout << "Hits: " << hit << endl;
    cout << "Hit Ratio: " << hitRatio << endl;

    return 0;
}