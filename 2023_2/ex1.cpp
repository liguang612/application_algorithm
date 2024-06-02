#include <iostream>
#include <vector>

using namespace std;

int n, res = 0;
vector<int> arr;

int main()
{
    // freopen("input.txt", "r", stdin);

    int tmp, cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    tmp = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= tmp) {
            res = res < cnt ? cnt : res;
            cnt = 1;
        }
        else {
            ++cnt;
        }
        tmp = arr[i];
    }

    cout << res;

    return 0;
}
