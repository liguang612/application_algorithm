#include <iostream>
#include <algorithm>

using namespace std;

int arr[21], M = 1000000000, N, sumLeft = 0, sumRight = 0, remaining = 0;

void attempt(int v) {
    if (v > N) {
        M = min(M, abs(sumLeft - sumRight));
        return;
    }
    for (int i = 1; i <= N; i++) {
        remaining -= arr[v];

        if (abs(sumLeft + arr[v] - sumRight) <= remaining + M) {
            sumLeft += arr[v];

            attempt(v + 1);

            sumLeft -= arr[v];
        }
        if (abs(sumRight + arr[v] - sumLeft) <= remaining + M) {
            sumRight += arr[v];

            attempt(v + 1);

            sumRight -= arr[v];
        }

        remaining += arr[v];
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        remaining += arr[i];
    }

    attempt(1);

    cout << M;

    return 0;
}
