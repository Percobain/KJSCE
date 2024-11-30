#include <bits/stdc++.h>
using namespace std;

class Consumer {
    public:
    int cno;
    string cname;
    int prev;
    int curr;
    string type;

    Consumer(int cno, string cname, int prev, int curr, string type) {
        this->cno = cno;
        this->cname = cname;
        this->prev = prev;
        this->curr = curr;
        this->type = type;
    }

    double calculate_bill() {
        int units = curr - prev;
        double bill = 0.0;

        if (type == "domestic") {
            if (units <= 100) bill = 1.0 * units;
            else if (units > 100 && units <= 200) bill = 100 * 1.0 + 2.5 * (units - 100);
            else if (units > 200 && units <= 500) bill = 100 * 1.0 + 2.5 * 100 + 4.0 * (units - 200);
            else bill = 100 * 1.0 + 2.5 * 100 + 4.0 * 300 + 6.0 * (units-500);
        }

        else {
            if(units <= 100) bill = 2.0 * units;
            else if(units > 100 && units <= 200) bill = 100 * 2.0 + 4.5 * (units-100);
            else if(units > 200 && units <= 500) bill = 100 * 2.0 + 200 * 4.5 + 6.0 * (units-200); 
            else bill = 100 * 2.0 + 100 * 4.5 + 300 * 6.0 + 7.0 * (units-500);
        }

        return bill;
    }

    void display_bill() {
        int units = curr - prev;
        double bill = calculate_bill();
        cout << "Consumer No: " << cno << endl;
        cout << "Consumer Name: " << cname << endl;
        cout << "Previous Reading: " << prev << endl;
        cout << "Current Reading: " << curr << endl;
        cout << "Type: " << type << endl;
        cout << "Units Consumed: " << units << endl;
        cout << "Bill Amount: " << bill << endl;
    }
};

int main() {
    int cno, prev, curr;
    string cname, type;

    cout << "Enter Consumer No: ";
    cin >> cno;

    cout << "Enter Consumer Name: ";
    cin >> cname;

    cout << "Enter Previous Reading: ";
    cin >> prev;

    cout << "Enter Current Reading: ";
    cin >> curr;

    cout << "Enter Type (domestic/commercial): ";
    cin >> type;

    cin.ignore();
    getline(cin, type);

    Consumer c(cno, cname, prev, curr, type);
    c.display_bill();
}