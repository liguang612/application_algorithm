#include <iostream>

using namespace std;

int main() {
    int a, *arr, b, n;

    cin >> n;
    arr = new int[n + 1];

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }

    return 0;
}