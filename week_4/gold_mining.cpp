#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l1, l2;
    cin >> n >> l1 >> l2;

    vector<int> gold(n + 1), dp(n + 1), max_gold(n + 1);
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        cin >> gold[i];
    }

    // Initialize
    for (int i = 1; i <= l1; i++)
    {
        dp[i] = gold[i];
        max_gold[i] = max(max_gold[i - 1], dp[i]);
    }
    // Execute
    for (int i = l1 + 1; i <= n; i++)
    {
        // Loại bỏ những vị trí không thể chạm tới i
        while (!dq.empty() && dq.front() + l2 < i)
        {
            dq.pop_front();
        }

        // Loại bỏ những thằng mà chắc chắn không cho ra kết quả tốt hơn
        while (!dq.empty() && dp[dq.back()] < dp[i - l1])
        {
            dq.pop_back();
        }
        dq.push_back(i - l1);
        // Cập nhật thôi ;)
        dp[i] = dp[dq.front()] + gold[i];

        max_gold[i] = max(max_gold[i - 1], dp[i]);
    }

    cout << max_gold[n];

    return 0;
}
