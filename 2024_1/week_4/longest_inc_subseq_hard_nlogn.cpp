#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> tails;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        if (it != tails.end())
        {
            *it = arr[i];
        }
        else
        {
            tails.push_back(arr[i]);
        }
    }

    cout << tails.size() << endl;
    return 0;
}
