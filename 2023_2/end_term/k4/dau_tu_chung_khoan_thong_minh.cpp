#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n1, n2, n, l, m, m1 = 0, m2 = 0, record = 0, s = 0;
vector<int> profit, res;
bool check[1000][1000] = {}, visited[1000] = {};

bool verify(int k)
{
    if (visited[k])
    {
        return false;
    }

    for (auto &&i : res)
    {
        if (check[i][k])
            return false;
    }
    return true;
}

void attempt()
{
    if (res.size() > l)
    {
        return;
    }
    else
    {
        if (record < s && m1 >= m && m2 >= m)
        {
            record = s;
        }
    }

    int lwr = 1;
    if (res.size() > 0)
    {
        lwr = res[res.size() - 1];
    }

    for (int i = lwr; i <= n; i++)
    {
        if (verify(i))
        {
            res.push_back(i);
            visited[i] = true;
            s += profit[i];
            if (i <= n1)
            {
                m1++;
            }
            else
            {
                m2++;
            }

            attempt();

            if (i <= n1)
            {
                m1--;
            }
            else
            {
                m2--;
            }
            s -= profit[i];
            visited[i] = false;
            res.pop_back();
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n1 >> n2;
    n = n1 + n2;

    int a, b, p;
    profit.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        profit.push_back(a);
    }

    cin >> l >> m;

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        check[a][b] = check[b][a] = true;
    }

    attempt();

    cout << record;

    return 0;
}