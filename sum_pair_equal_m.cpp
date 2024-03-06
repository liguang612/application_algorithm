#include <iostream>
#include <set>

using namespace std;

int main() {
    int count = 0, m, n, tmp, tmp2;
    set<int> s;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    set<int>::iterator cw = s.begin(), c_cw = s.end();
    c_cw--;

    while (cw != c_cw)
    {
        tmp2 = *cw + *c_cw;   
        if (tmp2 == m)
        {
            ++count;
            cw++;
        }
        else if(tmp2 > m) {
            c_cw--;
        }
        else {
            cw++;
        }
    }

    cout << count;

    return 0;
}