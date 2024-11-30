#include<bits/stdc++.h>
using namespace std;

int main() {
    int numPages, frames;
    cout << "Enter number of pages: ";
    cin >> numPages;

    cout << "Enter number of frames: ";
    cin >> frames;

    vector<int> pages(numPages);
    cout << "Enter page numbers: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    deque<int> cache;
    int hits = 0;
    cout << "\nFIFO Page Replacement Process: ";
    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        if (find(cache.begin(), cache.end(), currentPage) != cache.end()) {
            hits++;
            cout << "Cache: ";
            for (int page : cache) {
                cout << page << " ";
            }
            cout << endl;
        } else {
            if (cache.size() == frames) {
                cache.pop_front();
            }
            cache.push_back(currentPage);
            cout << "Cache: ";
            for (int page : cache) {
                cout << page << " ";
            }
            cout << endl;
        }
    }

    double hitRatio = (double)hits / numPages;
    cout << "\nTotal hits: " << hits << endl;
    cout << "Hit ratio: " << hitRatio << endl;

    return 0;
}