#include<bits/stdc++.h>
using namespace std;
int dd[10] = {};
int res = 0;
int n, Sum;
int X;
int vec[8] = { 0,1000,100,10010,2,1000,100,10 };

void Try(int u) {

    for (int i = 0;i < 10; i++) {
        if (i == 0) {
            if (u == 1 || u == 3) continue;
        }
        if (!dd[i]) {
            dd[i] = 1;
            Sum += i * vec[u];
            if (Sum <= X) {

                if (u == 7) res += (Sum == X);
                else Try(u + 1);
            }
            dd[i] = 0;
            Sum -= i * vec[u];
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> X;
        Sum = 0;
        res = 0;
        Try(1);
        cout << res << '\n';
    }
    return 0;
}