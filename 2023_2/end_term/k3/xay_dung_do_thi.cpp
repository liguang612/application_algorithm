#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct edge
{
    int s;
    int t;
    int weight;

    edge() {}
    edge(int s, int t, int w) : s(s), t(t), weight(w) {}

    bool operator<(const edge &other)
    {
        return weight < other.weight;
    }
} edge;

int n, m, x[751], y[751], parent[751], r[751] = {0};
vector<edge> edges;

int find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
    int pU = find(u), pV = find(v);
    if (pU != pV)
    {
        if (r[pU] < r[pV])
            parent[pU] = pV;
        else if (r[pV] < r[pU])
            parent[pV] = pU;
        else
        {
            parent[pU] = pV;
            r[pV]++;
        }

        return true;
    }

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    // init all road
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges.push_back(edge(i, j, (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])));
        }
    }

    // Process the road existed
    cin >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        merge(u, v);

        for (auto i = edges.begin(); i != edges.end(); i++)
        {
            if (i->s == u && i->t == v)
            {
                edges.erase(i);
                break;
            }
            else if (i->s == v && i->t == u)
            {
                edges.erase(i);
                break;
            }
        }
    }

    sort(edges.begin(), edges.end());

    int left = n - 1 - m, total = 0;

    while (left)
    {
        auto it = edges.begin();

        if (merge(it->s, it->t))
        {
            --left;
            total += it->weight;
        }

        edges.erase(it);
    }

    cout << total;

    return 0;
}