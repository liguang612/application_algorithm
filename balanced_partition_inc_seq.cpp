#include <iostream>

using namespace std;

long long int* arr, m, n;

bool scan(long long int c, long long int mid) {
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else {

            sum = arr[i];
            --c;
        }
    }
    if (sum < mid)
    {
        --c;
    }

    return (c >= 0);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long int low = 0, high = 0;

    cin >> n >> m;
    arr = new long long int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        high += arr[i];
    }

    while (low < high)
    {
        long long int mid = (low + high) / 2;

        if (scan(m, mid))
        {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low << endl;

    return 0;
}