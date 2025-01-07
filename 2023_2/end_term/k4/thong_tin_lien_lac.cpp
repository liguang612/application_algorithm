#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge
{
    int u, v;
    int weight;

    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

struct DisjointSets
{
    vector<int> parent, rank;

    DisjointSets(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v)
        {
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else
            {
                parent[root_u] = root_v;
                if (rank[root_u] == rank[root_v])
                    rank[root_v]++;
            }
        }
    }
};

int kruskal(int n, vector<Edge> &edges, int S)
{
    sort(edges.begin(), edges.end());

    DisjointSets ds(n);
    vector<int> mst_weights;

    for (Edge &e : edges)
    {
        if (ds.find(e.u) != ds.find(e.v))
        {
            ds.unite(e.u, e.v);
            mst_weights.push_back(e.weight);
        }
    }

    sort(mst_weights.begin(), mst_weights.end());
    return mst_weights[S - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);

    int S, P;
    cin >> S >> P;

    vector<pair<int, int>> points(P);
    for (int i = 0; i < P; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    vector<Edge> edges;
    for (int i = 0; i < P; i++)
    {
        for (int j = i + 1; j < P; j++)
        {
            int dist = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
            edges.push_back({i, j, dist});
        }
    }

    printf("%d\n", kruskal(P, edges, S));
    return 0;
}
