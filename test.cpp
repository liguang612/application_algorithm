#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int arr[] = {4,5,3,2};

    sort(arr, arr + 3);

    for (int i = 0; i < 4; i++)
    {
        cout << arr[i];
    }
}