#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef struct node
{
    int a, b, step;
    node(int a, int b, int step) : a(a), b(b), step(step) {}

    bool operator<(const node &n) const
    {
        if (a == n.a)
        {
            if (b == n.b)
            {
                return step < n.step;
            }
            return b < n.b;
        }
        return a < n.a;
    }
} node;

int a, b, c, step = -1;
queue<node> q;
set<node> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    q.push(node(0, 0, 0));
    s.insert(node(0, 0, 0));

    while (!q.empty())
    {
        node n = q.front();
        q.pop();

        if (n.a == c || n.b == c)
        {
            step = n.step;
            break;
        }

        if (n.a < a)
        {
            if (s.find(node(a, n.b, n.step + 1)) == s.end())
            {
                q.push(node(a, n.b, n.step + 1));
                s.insert(node(a, n.b, n.step + 1));
            }
        }

        if (n.b < b)
        {
            if (s.find(node(n.a, b, n.step + 1)) == s.end())
            {
                q.push(node(n.a, b, n.step + 1));
                s.insert(node(n.a, b, n.step + 1));
            }
        }

        if (n.a > 0)
        {
            if (s.find(node(0, n.b, n.step + 1)) == s.end())
            {
                q.push(node(0, n.b, n.step + 1));
                s.insert(node(0, n.b, n.step + 1));
            }
        }

        if (n.b > 0)
        {
            if (s.find(node(n.a, 0, n.step + 1)) == s.end())
            {
                q.push(node(n.a, 0, n.step + 1));
                s.insert(node(n.a, 0, n.step + 1));
            }
        }

        if (n.a > 0 && n.b < b)
        {
            int t = min(n.a, b - n.b);
            if (s.find(node(n.a - t, n.b + t, n.step + 1)) == s.end())
            {
                q.push(node(n.a - t, n.b + t, n.step + 1));
                s.insert(node(n.a - t, n.b + t, n.step + 1));
            }
        }

        if (n.b > 0 && n.a < a)
        {
            int t = min(n.b, a - n.a);
            if (s.find(node(n.a + t, n.b - t, n.step + 1)) == s.end())
            {
                q.push(node(n.a + t, n.b - t, n.step + 1));
                s.insert(node(n.a + t, n.b - t, n.step + 1));
            }
        }
    }

    cout << step;

    return 0;
}