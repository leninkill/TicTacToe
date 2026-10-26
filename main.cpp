#include <charconv>
#include <iostream>

using namespace std;

const int SIZE = 3;
string field[SIZE][SIZE];

string check(string s) {
    if (field[0][0] == s and field[0][1] == s and field[0][2] == s) {
        return s;
    }
    if (field[1][0] == s and field[1][1] == s and field[1][2] == s) {
        return s;
    }
    if (field[2][0] == s and field[2][1] == s and field[2][2] == s) {
        return s;
    }
    if (field[0][0] == s and field[1][0] == s and field[2][0] == s) {
        return s;
    }
    if (field[0][1] == s and field[1][1] == s and field[2][1] == s) {
        return s;
    }
    if (field[0][2] == s and field[1][2] == s and field[2][2] == s) {
        return s;
    }
    if (field[0][0] == s and field[1][1] == s and field[2][2] == s) {
        return s;
    }
    if (field[0][2] == s and field[1][1] == s and field[2][0] == s) {
        return s;
    }

    return "*";
}

int main() {
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

        if (field[userRow][userColumn] == "~") {
            field[userRow][userColumn] = turnChar;
        }

        for (auto &subitem: field) {
            for (auto &item: subitem) {
                cout << item << "\t";
            }
            cout << endl;
        }

        cout << endl;

        if (check("0") == "0") {
            cout << "WIN 0" << endl;
            break;
        } else if (check("X") == "X") {
            cout << "WIN X" << endl;
            break;
        } else if (check("*") == "*" and hod == 9)  {
            cout << "DRAW" << endl;
        }


        hod++;
    }

    return 0;
}