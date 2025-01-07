#include <iostream>
#include <queue>

using namespace std;

typedef struct mst_kruskal
{
    int u, v, w;

    mst_kruskal(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const mst_kruskal &a) const
    {
        return w > a.w;
    }
} mst_kruskal;

int m, n, parent[100002], s = 0;
priority_queue<mst_kruskal> pq;

pair<int, int> find(int x)
{
    if (parent[x] == x)
        return {x, 0};

    auto [root, weight] = find(parent[x]);
    parent[x] = root;
    return {root, weight + 1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push(mst_kruskal(u, v, w));
    }

    n--;
    while (true)
    {
        if (n == 0)
            break;

        if (pq.empty())
            break;

        mst_kruskal edge = pq.top();
        pq.pop();

        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        auto [rootU, rankU] = find(u);
        auto [rootV, rankV] = find(v);

        // u and v are in the same tree
        if (rootU == rootV)
            continue;

        if (rankU < rankV)
            parent[rootU] = rootV;
        else
            parent[rootV] = rootU;

        --n;
        s += w;
    }

    cout << s;

    return 0;
}