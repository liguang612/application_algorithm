// Cho dãy số, chọn dãy con (không cần liên tiếp) sao cho chẵn lẻ xen kẽ và tăng ngặt.
// In ra độ dài dãy con đó

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input2.txt", "r", stdin);

    int T;

    cin >> T;

    while (T--) {
        int n, arr[100002], dp[100002][2], res = 0;

        cin >> n;

        arr[0] = -1000;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] % 2) {
                for (int j = i - 1; j >= 0; j--) {
                    if (arr[j] < arr[i]) {
                        dp[i][0] = max(dp[i][0], dp[j][0]);
                        dp[i][1] = max(dp[i][1], dp[j][0] + 1);

                        break;
                    }
                }
            }
            else {
                for (int j = i - 1; j >= 0; j--) {
                    if (arr[j] < arr[i]) {
                        dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
                        dp[i][1] = max(dp[j][1], dp[i][1]);
                    }
                }
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }

        cout << res << endl;
    }


    return 0;
}
