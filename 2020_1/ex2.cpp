#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int n, dino;
    queue<int> q;
    vector<int> s;
    string signal;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dino;
        s.push_back(dino);
    }

    cin >> signal;
    for (auto i : signal)
    {
        if (i == 'C')
        {
            q.push(s[0]);
            s.erase(s.begin());
        }
        else {
            s.insert(s.begin(), q.front());
            q.pop();
        }
    }

    for (auto&& i : s)
    {
        cout << i << ' ';
    }

    return 0;
}