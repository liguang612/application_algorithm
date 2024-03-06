#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int *arr, *it, max = 0, n, q, *r_it, sum = 0;

    cin >> n >> q;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *end = arr + n;

    it = arr;
    r_it = arr;
    sum = arr[0];
    while (r_it != end)
    {
        while (sum <= q)
        {
            r_it++;
            if (r_it == end)
            {
                break;
            }
            
            sum += *r_it;
        }

        int tmp = r_it - it;
        max = max < tmp ? tmp : max;

        while (sum > q)
        {
            sum -= *it;
            it++;
        }
    }

    cout << max;

    delete[] arr;

    return 0;
}