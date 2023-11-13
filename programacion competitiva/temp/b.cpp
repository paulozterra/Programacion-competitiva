#include <bits/stdc++.h>
using namespace std;

void solve() {
    char arr[3][3];
    char a1;
    int gano = 0;
    int gano2 = 0;
    char temp;
    char temp2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a1;
            arr[i][j] = a1;
        }
    }
    for (int i = 0; i < 3; i++) {
        char temp = arr[i][0];
        for (int j = 1; j < 3; j++) {
            if (temp == arr[i][j] && arr[i][j] != '.') {
                gano++;
            } else {
                gano = 0;
            }
        }
        if (gano == 2 && temp != '.') {
            cout << temp << endl;
            return;
        }
        gano = 0;
    }
    for (int j = 0; j < 3; j++) {
        char temp2 = arr[0][j];
        for (int i = 1; i < 3; i++) {
            if (temp2 == arr[i][j] && arr[i][j] != '.') {
                gano2++;
            } else {
                gano2 = 0;
            }
        }
        if (gano2 == 2 && temp2 != '.') {
            cout << temp2 << endl;
            return;
        }
        gano2 = 0;
    }
    temp = 0;
    temp2=0;
    if (gano != 2 && gano2 != 2) {

        if (arr[0][0] != '.'){
            temp = arr[0][0];
        }
        if (arr[0][2] != '.'){
            temp2 = arr[0][2];
        }
        if (temp == arr[1][1] && temp == arr[2][2]) {
            cout << temp << endl;
        }
        else if (temp2 == arr[1][1] && temp2 == arr[2][0]) {

            cout << temp2 << endl;
        } else {
            cout << "DRAW" << endl;
        }
    }
}

int main() {
    long long int test = 0;
    cin >> test;
    for (long long int i = 0; i < test; i++) {
        solve();
    }
    return 0;
}

