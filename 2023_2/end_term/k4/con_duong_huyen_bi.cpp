#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minJumps(vector<int> &p)
{
    int n = p.size();
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        int upr = min(n - 1, i + p[i]);
        for (int j = i + 1; j <= upr; ++j)
        {
            if (dist[j] == INT_MAX)
            {
                dist[j] = dist[i] + 1;
                q.push(j);
            }
        }
    }

    return dist[n - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> p(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }

        cout << minJumps(p) << endl;
    }

    return 0;
}
