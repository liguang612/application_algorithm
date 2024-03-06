#include <iostream>

using namespace std;

int main() {
    int *arr = new int[2];

    int *it = arr, *_it = arr + 1;

    cout << _it - it;

    delete[] arr;

    return 0;
}