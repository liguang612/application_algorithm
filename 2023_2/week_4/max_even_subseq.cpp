#include <iostream>
#include <climits> // Để sử dụng LONG_LONG_MIN
using namespace std;

long long int arr, N, sum = 0, sum_max_even = LLONG_MIN, sum_max_odd = LLONG_MIN, sum_min_even = 0, sum_min_odd = 0;
long long int _max = LLONG_MIN;

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr;
        sum += arr;

        if (sum % 2 == 0)
        {
            sum_max_even = max(sum_max_even, sum);
            _max = max(_max, sum_max_even - sum_min_even);
            sum_min_even = min(sum_min_even, sum);
        }
        else
        {
            sum_max_odd = max(sum_max_odd, sum);
            _max = max(_max, sum_max_odd - sum_min_odd);
            sum_min_odd = min(sum_min_odd, sum);
        }
    }

    if (_max == LLONG_MIN)
        cout << "NOT_FOUND" << endl;
    else
        cout << _max << endl;

    return 0;
}
