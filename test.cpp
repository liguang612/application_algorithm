#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& sum, int target) {
    vector<int> res;

    int sz = sum.size();

    vector<int>::iterator it;
    for (int i = 0; i < sz; i++)
    {
        if ((it = find(sum.begin(), sum.end(), target - sum[i])) != sum.end())
        {
            if (it - sum.begin() != i)
            {
                res.push_back(i);
                res.push_back(it - sum.begin());

                return res;
            }

        }
    }

    return res;
}

int main() {
    vector<int> v = { 3,2,4 };

    auto r = twoSum(v, 6);

    for (auto&& i : r)
    {
        cout << i << ' ';
    }

    return 0;
}