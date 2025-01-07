#include <iostream>
#include <vector>

using namespace std;

int n, k, s = 0;
vector<int> v;

void display()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void gen()
{
    if (v.size() == n)
    {
        if (s == k)
            display();
        return;
    }

    int start = 1;
    if (v.size() > 0)
    {
        start = v[v.size() - 1];
    }

    for (int i = start; i <= k - s; i++)
    {
        v.push_back(i);
        s += i;

        gen();

        s -= i;
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    gen();

    return 0;
}