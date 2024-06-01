#include <iostream>
#include <vector>

using namespace std;

int c = 0, k, m, n;
vector<int> arr;

void attempt(vector<int> v) {
    if (v.size() == k + 1)
    {
        if (!m)
        {
            c++;
        }

        return;
    }

    for (int i = v[v.size() - 1] + 1; i < n; i++)
    {
        if (arr[i] <= m)
        {
            v.push_back(i);
            m -= arr[i];
            attempt(v);

            // Restore
            v.pop_back();
            m += arr[i];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int a;
    vector<int> v;

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    v.push_back(-1);
    attempt(v);

    cout << c;

    return 0;
}