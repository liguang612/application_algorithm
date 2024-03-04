#include <iostream>
#include <set>

using namespace std;

int main() {
    int a, n;
    set<int> arr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << !arr.insert(a).second << endl;
    }

    return 0;
}