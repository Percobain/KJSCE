#include <bits/stdc++.h>
using namespace std;

class Consumer {
    public:
        int consumer_no;
        string consumer_name;
        int previous_reading;
        int current_reading;
        string connection_type;

    Consumer(int cno, string name, int prev, int curr, string type):consumer_no(cno), consumer_name(name), previous_reading(prev), current_reading(curr), connection_type(type) {}

    double calculate_bill() {
        int units = current_reading - previous_reading;
        double bill = 0.0;

        if(connection_type=="domestic") {
            if(units <= 100) {
                bill = 1.0* units;
            }
            else if(units > 100 && units <= 200) {
                bill = 100 * 1.0 + 2.5 * (units-100);
            }
            else if(units>200 && units<=500) {
                bill = 100 * 1.0 + 2.5 * 100 + 4.0 * (units-200);
            } else {
                bill = 100 * 1.0 + 2.5 * 100 + 4.0 * 300 + 6.0 * (units-500);
            }
        }
        else {
            if(units <= 100) {
                bill = 2.0 * units;
            } else if(units > 100 && units <= 200) {
                bill = 100 * 2.0 + 4.5 * (units-100);
            } else if(units > 200 && units <= 500) {
               bill = 100 * 2.0 + 200 * 4.5 + 6.0 * (units-200);
            } else {
                bill = 100 * 2.0 + 100 * 4.5 + 300 * 6.0 + 7.0 * (units-500);
            }
        }
        return bill;
    }

    void display_bill()
    {
        int units = current_reading - previous_reading;

        cout <<""<<endl;
        cout << "DETAILS:"<<endl;
        cout << "Consumer Number: " << consumer_no << '\n';
        cout << "Consumer Name: " << consumer_name << '\n';
        cout << "Previous Reading: " << previous_reading << '\n';
        cout << "Current Reading: " << current_reading << '\n';
        cout << "Connection Type: " << connection_type << '\n';
        cout << "Units Consumed: " << units << '\n';
        cout << "Total Bill Amount: Rs. " << calculate_bill() << '\n';
    }
};

int main()
{
    int cno, prev, curr;
    string name, type;

    cout << "Enter Consumer Number: ";
    cin >> cno;

    cout << "Enter Consumer Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter previous reading: ";
    cin >> prev;

    cout << "Enter Current Reading: ";
    cin >> curr;

    cout << "Enter connection type: ";
    cin.ignore();
    getline(cin,type);

    Consumer obj(cno, name, prev, curr, type);
    obj.display_bill();
    
}