#include <iostream>
#include <vector>

using namespace std;

vector<int> outlet[10001], process;
int cost[10001], done = 0, inlet[10001], M, N, s = 0;

int min(vector<int> v) {
    int tmp = 10e9;

    for(auto i : v) {
        if (tmp > cost[i]) {
            tmp = cost[i];
        }
    }

    return tmp;
}

int main() {
    freopen("input.txt", "r", stdin);

    int a, b;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    for(int i = 1; i <= M; i++) {
        cin >> a >> b;
        inlet[b]++;
        outlet[a].push_back(b);
    }

    while (done < N) {
        for(int i = 1; i <= N; i++) {
            if (!inlet[i]) {
                --inlet[i]; // inlet == -1 : has completed
                process.push_back(i);
            }
        }

        int _min = min(process);

        s += _min;

        for(auto i = process.begin(); i != process.end(); i++) {
            int cur = *i;
            if (!(cost[cur] -= _min)) {
                process.erase(i);
                i--;
                ++done;

                for(int j : outlet[cur]) {
                    --inlet[j];
                }
            }
        }
    }

    cout << s;

    return 0;
}
