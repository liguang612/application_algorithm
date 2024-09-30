#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cnt = 0, n, p0, px;
    double maxDegree = -100000;

    cin >> n;

    cin >> p0;
    for (int i = 1; i < n; i++)
    {
        cin >> px;

        double d = (px - p0 + 0.0) / i;

        if (d > maxDegree)
            cnt++;

        maxDegree = max(maxDegree, d);
    }

    cout << cnt;

    return 0;
}