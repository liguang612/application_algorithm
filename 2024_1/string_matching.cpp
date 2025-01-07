#include <iostream>
#include <string>

using namespace std;

string p, t;
int last[128];
int n, m, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, p);
    getline(cin, t);

    m = p.size();
    n = t.size();

    for (int i = 0; i < m; i++)
    {
        last[p[i]] = i;
    }

    bool b;
    for (int i = 0; i <= n - m;)
    {
        b = true;
        for (int j = m - 1; j >= 0; j--)
        {
            if (t[i + j] != p[j])
            {
                i += max(1, j - last[t[i + j]]);
                b = false;

                break;
            }
        }

        if (b)
        {
            cnt++;
            i++;
        }
    }

    cout << cnt;

    return 0;
}