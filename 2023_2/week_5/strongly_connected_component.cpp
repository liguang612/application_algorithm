#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> edges;
int cnt = 0, cur = 0, E, low[10001], num[10001], V;
bool onStack[10001];
stack<int> S;

void scc(int v)
{
    low[v] = num[v] = ++cur;
    S.push(v);
    onStack[v] = true;

    for (auto& u : edges[v])
    {
        if (num[u] == -1)
        {
            scc(u);
            low[v] = min(low[v], low[u]);
        }
        else if (onStack[u])
        {
            low[v] = min(low[v], num[u]);
        }
    }

    if (low[v] == num[v])
    {
        ++cnt;
        int u;
        do
        {
            u = S.top();
            S.pop();
            onStack[u] = false;
        } while (u != v);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int a, b;

    cin >> V >> E;

    edges.resize(V + 1);
    fill(num, num + V + 1, -1);
    fill(onStack, onStack + V + 1, false);

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for (int i = 1; i <= V; i++)
    {
        if (num[i] == -1)
        {
            scc(i);
        }
    }

    cout << cnt;

    return 0;
}
