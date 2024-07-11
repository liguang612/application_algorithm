#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10005] = {};
int dp[10005] = {};
int main()
{
    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> arr[i];
        }
        int res = -1;
        for (int i = 1;i <= n;i++) {
            dp[i] = 1;
            for (int j = 1;j < i;j++) {
                if (arr[j] < arr[i] && ((arr[i] + arr[j]) % 2 != 0)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }

    return 0;
}