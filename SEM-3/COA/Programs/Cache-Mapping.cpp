#include <bits/stdc++.h>
using namespace std;


// Direct Mapping Implementation / Associative Mapping Implementation
int main() {
    int n, m;
    cout << "Enter number of pages: ";
    cin >> n;
    cout << "Enter number of cache lines: ";
    cin >> m;

    vector<int> cac1(m, -1);
    vector<int> cac2(m, -1);
    vector<int> cac3(m, -1);

    int t = 1;
    while (t == 1) {
        cout << "1. Memory Line: \n";
        cout << "2. Exit \n";
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;

        switch(ch) {
            case 1: {
                cout << "Enter line number: ";
                int x;
                cin >> x;
                if (x >= n || x < 0) cout << "Wrong Input! \n";
                else {
                    int ver = x % m;
                    if (cac1[ver] == -1 || cac2[ver] == -1 || cac3[ver] == -1) {
                        if (cac1[ver] == -1) {
                            cout << "Adding to 1st Cache line: " << ver << '\n';
                            cac1[ver] = x;
                        }
                        else if (cac2[ver] == -1) {
                            cout << "Adding to 2nd Cache line: " << ver << '\n';
                            cac2[ver] = x;
                        }
                        else {
                            cout << "Adding to 3rd Cache line: " << ver << '\n';
                            cac3[ver] = x;
                        }
                    }
                    else {
                        cout << "Cache Line: " << ver << " can't be added. \n";
                        cout << "1st Cache line occupied by: " << cac1[ver] << '\n';
                        cout << "2nd Cache line occupied by: " << cac2[ver] << '\n';
                        cout << "3rd Cache line occupied by: " << cac3[ver] << '\n';
                    }
                }
                break;
            }
            case 2:
                t = 0;
                break;
            
            default:
                cout << "Invalid Choice! \n";
                break;
        }
    }
    return 0;
}


// Set Associative Mapping Implementation
int main() {
    int n, m;
    cout << "Number of pages in memory: ";
    cin >> n;
    cout << "Number of lines in cache: ";
    cin >> m;

    vector<int> cac(m, -1);

    int t = 1;
    while (t == 1) {
        cout << "1. The Memory line: \n";
        cout << "2. Exit \n";
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter line number: " << '\n';
                int x;
                cin >> x;
                if (x > n || x < 0) {
                    cout << "Wrong Input! \n";
                }
                else {
                    int ver = x % m;
                    if (cac[ver] == -1) {
                        cout << "Adding to Cache Line: " << ver << '\n';
                        cac[ver] = x;
                    }
                    else {
                        cout << "Cache Line: " << ver << " can't be added. \n";
                        cout << "Cache Line already occupied by " << cac[ver] << '\n';
                    }
                }
                break;
            
            case 2:
                t = 0;
                break;
            
            default:
                cout << "Invalid Choice! \n";
                break;
        }
    }
    return 0;
}