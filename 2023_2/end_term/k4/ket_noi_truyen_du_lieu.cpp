#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int n, m, s, t, total = 0;
unordered_map<int, unordered_map<int, int>> graph;
vector<int> dist(1001, 1e9), ts;
unordered_set<pair<int, int>, pair_hash> road;

void reset()
{
    for (int i = 0; i <= n; i++)
        dist[i] = 1e9;
}

void bfs(int s, int d)
{
    reset();

    int parent[1001] = {0};
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto e : graph[x])
        {
            if (dist[e.first] > dist[x] + e.second)
            {
                parent[e.first] = x;
                dist[e.first] = dist[x] + e.second;

                q.push(e.first);
            }
        }
    }

    while (parent[d])
    {
        if (parent[d] < d)
        {
            road.insert({parent[d], d});
        }
        else
        {
            road.insert({d, parent[d]});
        }

        d = parent[d];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> m >> s;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        ts.push_back(a);
    }

    for (auto &&i : ts)
    {
        bfs(i, s);
    }

    for (auto &&i : road)
    {
        cout << i.first << ' ' << i.second << endl;
        total += graph[i.first][i.second];
    }

    cout << total;

    return 0;
}