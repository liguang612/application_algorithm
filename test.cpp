#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> m;

    m[1] = 2;
    m[3] = 4;

    auto it = m.end();
    it--;

    cout << it->first;

    return 0;
}