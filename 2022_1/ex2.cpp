#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int a, n;
    map<int, int> repo;
    string command;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        repo[a]++;
    }

    cin >> command;
    while (command != "*")
    {
        if (command == "insert")
        {
            cin >> a;
            repo[a]++;
        }
        else {
            auto it = repo.end();
            it--;
            cout << it->first << endl;
            it->second--;

            if (!(it->second))
            {
                repo.erase(it);
            }
        }

        cin >> command;
    }

    return 0;
}