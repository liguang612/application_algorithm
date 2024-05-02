#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(12);

    cout << *(v.end() - 1);

    return 0;
}