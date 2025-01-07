#include <iostream>
#include <vector>

using namespace std;

int n, arr[1000001];
vector<int> v, p;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int tmpMin = arr[1], peak = 1;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] < tmpMin)
        {
            tmpMin = arr[i];
            peak++;
        }
    }

    return 0;
}