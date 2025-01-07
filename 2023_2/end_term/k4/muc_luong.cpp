#include <iostream>

using namespace std;

int _min = INT32_MAX, _max = 0, arr[1000000], n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < _min)
            _min = arr[i];
        if (arr[i] > _max)
            _max = arr[i];
    }

    cout << _max << " " << _min;

    return 0;
}