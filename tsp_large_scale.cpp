#include <iostream>

using namespace std;

unsigned int** dist, _final[1001], minium = -1, n, route[1001];

void tsp(int start) {
    bool visited[1001] = { false };
    int _cost = 0;

    route[1] = start;
    visited[start] = true;

    for (int i = 2; i <= n; i++)
    {
        unsigned int index = 0, _min = -1;
        unsigned int* temp = dist[route[i - 1]]; // Just for boosting browsing

        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false && temp[j] < _min)
            {
                _min = temp[j];
                index = j;
            }
        }

        visited[index] = true;
        route[i] = index;
        _cost += _min;
        if (_cost >= minium)
        {
            return;
        }
    }

    _cost += dist[route[n]][start];
    if (_cost < minium)
    {
        minium = _cost;
        for (int i = 1; i <= n; i++)
        {
            _final[i] = route[i];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    dist = new unsigned int* [n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = new unsigned int[n + 1];
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        tsp(i);
    }

    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << _final[i] << ' ';
    }

    return 0;
}