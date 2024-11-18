#include <iostream>

using namespace std;
int n;

int a[1000005] = {};
long long S;
long long Min0 = 0; // Tong S QK CH nho nhat
long long Min1 = 0; // Tong S QK LE nho nhat
long long res = -1e9 + 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S = S + a[i];
        if (S % 2 == 0)
        {
            res = max(res, S - Min0);
            Min0 = min(S, Min0);
        }
        else
        {
            if (Min1 != 0)
            {
                res = max(res, S - Min1);
                Min1 = min(S, Min1);
            }
            else
            {
                Min1 = S;
            }
        }
    }
    cout << res;
}
