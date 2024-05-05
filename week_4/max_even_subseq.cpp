#include <iostream>

using namespace std;

long long int arr, N, sum, sum_max_even, sum_max_odd, sum_min_even, sum_min_odd;
long long int _max = -1;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    cin >> arr;
    sum = arr;
    // Prefix sum from 0 to N - 1
    for (int i = 1; i < N; i++)
    {
        cin >> arr;
        if (sum % 2)
        {
            sum_max_odd = max(sum_max_odd, sum);
            sum_min_odd = min(sum_min_odd, sum);

            _max = max(sum_max_odd - sum_min_odd, _max);
        }
        else {
            sum_max_even = max(sum_max_even, sum);
            sum_min_even = min(sum_min_even, sum);

            _max = max(sum_max_even - sum_min_even, _max);
        }

        sum += arr;
    }
    // and now, we need to calculate the last
    if (sum % 2)
    {
        sum_max_odd = max(sum_max_odd, sum);
        sum_min_odd = min(sum_min_odd, sum);

        _max = max(sum_max_odd - sum_min_odd, _max);
    }
    else {
        sum_max_even = max(sum_max_even, sum);
        sum_min_even = min(sum_min_even, sum);

        _max = max(sum_max_even - sum_min_even, _max);
    }

    cout << _max;

    return 0;
}