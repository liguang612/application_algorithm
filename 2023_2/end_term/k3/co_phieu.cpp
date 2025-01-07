#include <iostream>
#include <vector>

using namespace std;

int n1, n2, n, l, m, m1, m2, p, cnt = 0;
bool conflict[25][25], visited[25];
vector<int> res;

bool check(int k)
{
    if (visited[k])
        return false;

    for (auto &&i : res)
        if (conflict[i][k])
            return false;

    if (k > n1 && !m2)
        return false;

    if (k <= n1 && !m1)
        return false;

    return true;
}

void attempt()
{
    if (res.size() > l)
        return;
    else if (m1 < m && m2 < m)
    {
        cnt++;
    }

    int lwr = 1;
    if (res.size())
        lwr = res[res.size() - 1] + 1;

    for (int i = lwr; i <= n; i++)
    {
        if (check(i))
        {
            if (i > n1)
                m2--;
            else
                m1--;
            visited[i] = true;
            res.push_back(i);

            attempt();

            res.pop_back();
            visited[i] = false;
            if (i > n1)
                m2++;
            else
                m1++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n1 >> n2;
    n = n1 + n2;

    cin >> l >> m >> p;
    m1 = m2 = m;

    // Init
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            conflict[i][j] = conflict[j][i] = false;
        visited[i] = false;
    }

    int a, b;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }

    attempt();

    cout << cnt;

    return 0;
}