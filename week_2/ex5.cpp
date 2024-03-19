#include <iostream>
#include <algorithm>

using namespace std;

bool v[13];
int c[13][13], cmin = INT16_MAX, cond = 0, d[13], firstPoint[6], K, load[6], n, nbr, nextPoint[13], Q;
unsigned int dist = 0, record = -1;

bool checkPoint(int point, int k) {
    // If this point has been delivered
    if (point > 0 && v[point])
    {
        return false;
    }
    //Oh no, the car can't load any more
    if (load[k] + d[point] > Q)
    {
        return false;
    }
    return true;
}

void attemptPoint(int fP, int k) {
    if (!fP)
    {
        if (k < K)
        {
            attemptPoint(firstPoint[k], k + 1);
            return;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (checkPoint(i, k))
        {
            // Update
            nextPoint[fP] = i;
            v[i] = true;
            dist += c[fP][i];
            load[k] += d[i];
            ++cond;

            if (!i)
            {
                if (dist + (n + nbr - cond) * cmin < record)
                {
                    attemptPoint(i, k);
                }
            } else {
                if (k == K)
                {
                    if (cond == n + nbr)
                    {
                        record = min(dist, record);
                    }
                } else {
                    if (dist + (n + nbr - cond) * cmin < record)
                    {
                        attemptPoint(firstPoint[k + 1], k + 1);
                    }
                }
            }

            // Restore
            --cond;
            dist -= c[fP][i];
            load[k] -= d[i];
            v[i] = false;
        }
    }
}

bool checkCar(int point, int k) {
    // Yeah, car returned home
    if (point == 0)
    {
        return true;
    }
    // Oh no, car can't load more
    if (load[k] + d[point] > Q)
    {
        return false;
    }
    // This point has been delivered
    if (v[point])
    {
        return false;
    }

    return true;
}

void attemptCar(int k) {
    int s = 0;

    if (firstPoint[k - 1] > 0)
    {
        s = firstPoint[k - 1] + 1; // Set the lower bound of value can be the first point of this car
    }
    for (int i = s; i <= n; i++)
    {
        if (checkCar(i, k))
        {
            firstPoint[k] = i;

            if (!i)
            {
                ++cond;
            }
            
            //Update
            dist += c[0][i];
            load[k] += d[i];
            v[i] = true;

            if (k < K)
            {
                attemptCar(k + 1);
            } else {
                nbr = cond;

            }

            // Restore
            dist -= c[0][i];
            load[k] -= d[i];
            v[i] = false;

            if (!i)
            {
                --cond;
            }
        }
        
    }
    
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n >> K >> Q;

    // Input demand
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    
    // Input distance
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }

    firstPoint[0] = 0;
    attemptCar(1);

    cout << record;
    
    return 0;
}