#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

int in[10001], memory_in[10001], out[10001], res = INT_MAX;
vector<pair<int, int>> edges[10001];

int m, n, s, t;

void display(vector<int> v) {
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    int slice = 0;
    vector<int> q;

    cin >> n >> m >> s >> t;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        in[b] += c;
        out[a] += c;

        edges[a].push_back({ b,c });
    }

    memcpy(memory_in, in, n + 1);

    q.push_back(s);

    while (true)
    {
        if (q[0] == t)
        {
            break;
        }

        for (auto i : edges[q[0]])
        {
            slice += i.second;
            if ((in[i.first] -= i.second) == 0) {
                q.push_back(i.first);
            }
        }
        slice -= memory_in[q[0]];

        q.erase(q.begin());

        if (slice < res)
        {
            res = slice;

            display(q);
        }

    }

    cout << res << endl;

    return 0;
}