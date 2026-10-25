#include <iostream>

using namespace std;

int main() {
    const int SIZE = 3;
    string field[SIZE][SIZE];

    for (auto &subitem: field) {
        for (auto &item: subitem) {
            item = "~";
            cout << item << "\t";
        }
        cout << endl;
    }

    int hod = 0;
    bool win = false;

    int userRow;
    int userColumn;

    string turnChar;

    while (!win) {
        if (hod % 2 == 0) {
            turnChar = "X";
        } else {
            turnChar = "0";
        }

        cout << "Turn " << turnChar << endl;
        cin >> userRow;
        cin >> userColumn;

        field[userRow][userColumn] = turnChar;

        for (auto &subitem: field) {
            for (auto &item: subitem) {
                cout << item << "\t";
            }
            cout << endl;
        }

        hod++;
    }

    return 0;
}