#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100000], _min = 1000000000, _max = 0;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        _min = min(_min, a);
        _max = max(_max, a);
    }

    cout << _min << ' ' << _max;

    return 0;
}