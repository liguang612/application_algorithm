#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, ** maps, n;
    long long int** res;

    map<pair<int, int>, int> treasures;
    unordered_set<int> sX, sY;
    vector<int> X, Y;

    cin >> n;

    // Input and eliminate duplication
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        treasures[make_pair(a, b)] += c;
        sX.insert(a);
        sY.insert(b);
    }

    // We don't want to use <set>, let's convert to <vector> ...
    for (auto i : sX)
    {
        X.push_back(i);
    }
    for (auto i : sY)
    {
        Y.push_back(i);
    }
    // ... then sort it.
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    a = X.size();
    b = Y.size();
    maps = new int* [a], res = new long long int* [a];
    for (int i = 0; i < a; i++)
    {
        maps[i] = new int[b], res[i] = new long long int[b];
        for (int j = 0; j < b; j++)
        {
            maps[i][j] = treasures[make_pair(X[i], Y[j])];
            res[i][j] = max(i > 0 ? res[i - 1][j] : 0, j > 0 ? res[i][j - 1] : 0) + maps[i][j];
        }
    }

    cout << res[a - 1][b - 1];

    return 0;
}