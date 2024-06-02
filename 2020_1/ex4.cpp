#include <bits/stdc++.h>

using namespace std;

const double esp = 0.000000001;

int n, k;
double a[100005], b[100005];

bool check(double val) {
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i] - val;

    double mi = 0;
    for (int i = k; i <= n; i++) {
        mi = min(mi, b[i - k]);
        if (b[i] - mi > esp) return true;
    }

    return false;
}

double bina() {
    double l = 0.0, r = 5000000.0, res;
    for (int i = 1; i <= 100; i++) {
        double m = (l + r) / 2.0;
        if (check(m)) {
            res = m;
            l = m;
        }
        else r = m;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << fixed << setprecision(5) << bina();
}