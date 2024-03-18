#include <iostream>
#include <unordered_map>

using namespace std;

bool** conflict;
int *load, m, n, *teacher;
unsigned int record = -1;
unordered_map<int, bool>* preferences;

bool check(int c, int t) {
    // If the course is in the prefer list of the teacher
    if (!preferences[t][c])
    {
        return false;
    }

    // If current load is "going to be" :) bigger than record, needn't to go on
    if (load[t] == record)
    {
        return false;
    }

    // Try to find conflict
    for (int i = 1; i < c; i++)
    {
        if (teacher[i] == t && conflict[i][c])
        {
            return false; // If found conflict
        }
    }
    return true;
}

void update() {
    record = load[1];
    for (int i = 2; i <= n; i++)
    {
        if (load[i] > record)
        {
            record = load[i];
        }
    }
}

// (course: k)
void attempt(int k) {    
    // Browse all teacher (teacher: i)
    for (int i = 0; i < m; i++)
    {
        if (check(k, i))
        {
            // Update
            teacher[k] = i;
            ++load[i];

            // Load condition has been checked in check()
            // attempt(k + 1);
            if (k == n)
            {
                update();
            }
            else {
                if (load[i] < record)
                {
                    attempt(k + 1);
                }
            }

            // Restore
            --load[i];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int k, k1, k2;

    cin >> m >> n;
    
    conflict = new bool*[n + 1];
    for (int i = 1; i <= n; i++)
    {
        conflict[i] = new bool[n + 1];
        for (int j = 1; j <= n; j++)
        {
            conflict[i][j] = false; // Not conflict -> false
        }
    }

    load = new int[m];
    for (int i = 0; i < m; i++)
    {
        load[i] = 0;
    }
    
    // Initialize preferences
    preferences = new unordered_map<int, bool>[m];
    for (int i = 0; i < m; i++)
    {
        int tmp, _tmp;

        cin >> tmp;

        for (int j = 0; j < tmp; j++)
        {
            cin >> _tmp;
            preferences[i][_tmp] = true;
        }
    }

    teacher = new int[n + 1];

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> k1 >> k2;
        conflict[k1][k2] = true; // Conflict -> true
        // conflict[k2][k1] = true; // Conflict -> true
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << conflict[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    

    attempt(1);

    cout << (int)record;

    return 0;
}