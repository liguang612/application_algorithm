#include <iostream>
#include <string>

using namespace std;

const int Q = 1e9 + 2277; // 10e9 + 2277: Iêu anh Việt

long long int hashCode(string p) {
    long long int c = 0;

    for (char i : p)
    {
        c = c * 256 + i;
        c %= Q;
    }

    return c;
}

long long int hashCode(string s, int start, int end) {
    long long int c = 0;
    for (int i = start; i <= end; i++) {
        c = c * 256 + s[i];
        c %= Q;
    }
    return c;
}

long long int Pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long int res = Pow(a, b / 2);
    res = (res * res) % Q;
    if (b % 2) res = (res * a) % Q;

    return res;
}

int rabinKarp(string p, string t) {
    int cnt = 0, N = t.length(), M = p.length();
    if (M > N) return 0; // Nếu mẫu dài hơn chuỗi thì không có kết quả

    long long int e = Pow(256, M - 1);
    long long int codeP = hashCode(p), codeT = hashCode(t, 0, M - 1);

    for (int i = 0; i <= N - M; i++) {
        if (codeP == codeT) {
            bool ok = true;
            for (int j = 0; j < M; j++) {
                if (p[j] != t[j + i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++cnt;
            }
        }
        if (i < N - M) {
            long long int T = (t[i] * e) % Q;
            codeT = (codeT - T + Q) % Q;
            codeT = (codeT * 256 + t[i + M]) % Q;
        }
    }

    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);

    string p, t;

    getline(cin, p);
    getline(cin, t);

    cout << rabinKarp(p, t);

    return 0;
}
