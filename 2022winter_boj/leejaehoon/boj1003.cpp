#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int Acnt_0 = 1;
int Acnt_1 = 0;

int Bcnt_0 = 0;
int Bcnt_1 = 1;

int sum_0;
int sum_1;

void binPrint() {
    sum_0 = Acnt_0 + Bcnt_0;
    sum_1 = Acnt_1 + Bcnt_1;
    Acnt_0 = Bcnt_0;
    Acnt_1 = Bcnt_1;
    Bcnt_0 = sum_0;
    Bcnt_1 = sum_1;
}

int main() {
    int T;
    cin >> T;

    int n[100] = { 0, };
    for (int i = 0;i < T;i++) {
        cin >> n[i];
    }

    for (int i = 0;i < T;i++) {
        if (n[i] == 0) {
            cout << Acnt_0 << ' ' << Acnt_1 << '\n';
            continue;
        }
        if (n[i] == 1) {
            cout << Bcnt_0 << ' ' << Bcnt_1 << '\n';
            continue;
        }
        for (int j = 0;j < n[i] - 1;j++)
            binPrint();
        cout << sum_0 << ' ' << sum_1 << '\n';

        Acnt_0 = 1;
        Acnt_1 = 0;

        Bcnt_0 = 0;
        Bcnt_1 = 1;
    }
}
