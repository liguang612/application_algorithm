#include <iostream>
#include <vector>

using namespace std;

int n, a, b, c = 0;
vector<int> arr;

void attempt(vector<int> v, int s) {
    if (a <= s && s <= b) {
        c++;
    }

    for (int i = v[v.size() - 1] + 1; i < n; i++)
    {
        if (arr[i] + s <= b)
        {
            v.push_back(i);
            attempt(v, s + arr[i]);

            // Restore
            v.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int x;
    vector<int> v;

    v.push_back(-1);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    attempt(v, 0);

    cout << c;

    return 0;
}