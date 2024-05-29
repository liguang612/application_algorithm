#include <iostream>

using namespace std;

bool check(int n) {
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }

    }
    return true;
}

int main() {
    cout << check(1000000009);
}