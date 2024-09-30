#include <iostream>

using namespace std;

int main()
{
    int n, *arr, *sum;

    cin >> n;
    arr = new int[n];

    cin >> arr[0];
    sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (sum[i] - arr[i] == sum[n - 1] - sum[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}