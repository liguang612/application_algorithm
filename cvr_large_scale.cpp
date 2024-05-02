#include <iostream>
#include <vector>

using namespace std;

bool visited[13];
unsigned int c[13][13], cost = 0, d[13], K, n, Q;
vector<int> path;

void tsp(int _n) {
    int num = _n;

    path.push_back(0);
    visited[0] = true;
    while (_n)
    {
        unsigned int imin, min = -1, * temp = c[*(path.end() - 1)];
        for (int i = 1; i <= num; i++)
        {
            // Find index min && min
            if (!visited[i] && temp[i] < min)
            {
                imin = i;
                min = temp[i];
            }
        }

        cost += min;
        path.push_back(imin);
        visited[imin] = true;

        _n--;
    }
}

void milestone() {
    int weight = Q;

    for (int i = 1; i <= n; i++)
    {
        if (d[path[i]] > weight) {
            cost += c[path[i - 1]][0] + c[0][path[i]];
            --K;
            weight = Q;
        }
        else {
            weight -= d[path[i]];
        }
        if (!K)
        {
            return;
        }
    }
    cost += c[path[n]][0];
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }

    tsp(n);
    milestone();

    cout << cost;

    return 0;
}