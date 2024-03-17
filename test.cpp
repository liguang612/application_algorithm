#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int len, min = 100000;
    string str;
    unordered_map<char, int> map;

    cin >> str;
    
    auto left = str.begin();
    auto right = str.end();

    // Initialize left bound
    while (left != right)
    {
        if (map[*left] == 1)
        {
            break;
        }
        ++map[*(left++)];
    }

    min = right - left; // Initialize min

    // The most ideal!
    if (min == 0)
    {
        cout << min;
        return 0;
    }

    while (right != left)
    {
        --right;

        cout << "Left: " << *left << "Right: " << *right << endl;
        getchar();
        if (map[*right] == 0)
        {
            ++map[*right];

            // Update min
            if (right - left < min)
            {
                min = right - left;
            }
        } else {
            if (left == str.begin())
            {
                break;
            }
            --map[*(--left)]; // Shift to left
            ++right; // Restore right
        }
    }

    cout << min;
    
    return 0;
}