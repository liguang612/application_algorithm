#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int c = 0, prev = 1000000000, next, n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> next;
        if (next < prev)
        {
            c++;
        }
        prev = next;
    }

    cout << c;

    return 0;
}