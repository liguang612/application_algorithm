#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<string> arr = { "Quoc", "Long", "Hai" };
    string tmp = "Long";

    reverse(tmp.begin(), tmp.end());

    cout << tmp;

    return 0;
}