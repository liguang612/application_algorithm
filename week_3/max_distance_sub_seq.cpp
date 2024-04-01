#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int *arr, c, n, T;

bool scan(int _c, int d) {
    int last = arr[0];
    --_c;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= d)
        {
            --_c;
            last = arr[i];
            if (!_c)
            {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n >> c;

        arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        int low = 0, high = arr[n - 1] - arr[0];

        while (low < high)
        {
            int mid = (low + high + 1) / 2;

            if (scan(c, mid))
            {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << low << endl;
    }

    return 0;
}