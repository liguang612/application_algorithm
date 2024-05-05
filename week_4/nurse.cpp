#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    // off: plan for i days that the last day is day-off, otherwise, on: ...
    unsigned int k1, k2, n, off[1002], on[1002];
    unsigned int lwr, upr; // Just for boost performance

    cin >> n >> k1 >> k2;

    // Initialize
    off[0] = on[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        off[i] = on[i] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        off[i + 1] += on[i]; // You have had a working period, let's relax tomorrow!

        lwr = i + k1;
        upr = min(i + k2, n); // Controll to avoid write in denied permission memory
        for (int j = lwr; j <= upr; j++)
        {
            on[j] += off[i]; // You had enjoyed a day-off? Let's have a k-day working...
        }
    }

    cout << on[n] + off[n];

    return 0;
}