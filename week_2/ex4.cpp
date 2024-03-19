#include <iostream>
#include <unordered_map>

using namespace std;

bool conflict[31][31];
int m, n, teacher[31];
unsigned int load[11], record = -1;
unordered_map<int, bool> preferences[31];

bool check(int c, int t) {
    // If the course isn't in the prefer list of the teacher
    if (!preferences[c][t])
    {
        return false;
    }

    // Try to find conflict
    for (int i = 1; i < c; i++)
    {
        if (teacher[i] == t && (conflict[i][c] || conflict[c][i]))
        {
            return false; // If found conflict
        }
    }
    return true;
}

void update() {
    record = load[1];
    for (int i = 2; i <= m; i++)
    {
        if (load[i] > record)
        {
            record = load[i];
        }
    }
}

// (course: k)
void attempt(int k) {
    if (k == n + 1)
    {
        update();
        return;
    }
    
    // Browse all teacher (teacher: i)
    for (int i = 1; i <= m; i++)
    {
        if (check(k, i))
        {
            // Update
            teacher[k] = i;
            ++load[i];

            // Load condition has been checked in check()
            if (load[i] < record)
            {
                attempt(k + 1);
            }

            // Restore
            --load[i];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k, k1, k2, tmp, _tmp;

    cin >> m >> n;
    
    // Initialize preferences
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp;

        for (int j = 0; j < tmp; j++)
        {
            cin >> _tmp;
            preferences[_tmp][i] = true;
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> k1 >> k2;
        conflict[k1][k2] = true; // Conflict -> true
        conflict[k2][k1] = true; // Conflict -> true
    }

    attempt(1);

    cout << record;

    return 0;
}