#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool* visited;
int m, n;
set<int>* tree;

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    visited = new bool[n + 1];
    tree = new set<int>[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int r = q.front();

            cout << r << ' ';

            q.pop();
            for (auto i : tree[r])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }



    return 0;

}