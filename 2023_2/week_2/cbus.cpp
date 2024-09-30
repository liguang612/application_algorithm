#include <iostream>
#include <algorithm>

using namespace std;

bool* visited;
int best = INT16_MAX, c_min = INT16_MAX, **d, f = 0, load, n, *x;

bool check(int v) {
    if (visited[v]) // Has come this milestone
    {
        return false;
    }
    if (v > n)
    {
        return visited[v - n]; // Has taken the passenger yet?
    }
    return load; // Return any seats else or not
}

void updateBest() {
    best = min(f + d[x[2 * n]][0], best);
}

void attempt(int milestones) {
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(i))
        {
            // cout << milestones << ": ";
            x[milestones] = i; // Store the milestones of route
            f += d[x[milestones - 1]][i]; // Add the distance
            visited[i] = true; // Flag where has gone

            // displayx();
            // cout << "f: " << f << endl;
            // displayv();
            // cout << best << endl << endl;

            // Upaate seats
            if (i <= n)
            {
                --load;
            } else {
                ++load;
            }
            if (milestones == 2 * n)
            {
                updateBest();
            } else {
                if (f + c_min * (2 * n + 1 - milestones) < best)
                {
                    attempt(milestones + 1); // Recursion
                }
            }
            
            // Restore
            if (i <= n)
            {
                ++load;
            } else {
                --load;
            }
            f -= d[x[milestones - 1]][i];
            visited[i] = false;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> load;

    d = new int*[2 * n + 1];
    visited = new bool[2 * n + 1];
    x = new int[2 * n + 1];
    
    for (int i = 0; i <= 2 * n; i++)
    {
        d[i] = new int[2 * n + 1];
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if (i != j) {
                c_min = min(c_min, d[i][j]);
            }
        }
    }
    visited[0] = true;
    for (int i = 1; i <= 2 * n; i++)
    {
        visited[i] = false;
    }
    x[0] = 0;

    attempt(1);
    
    cout << best << endl;
    
    return false;
}