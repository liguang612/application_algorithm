#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool check = true;
unordered_map<string, int> numOfCalls, totalTimeOfCalls;

bool isPhonenumber(string s)
{
    if (s.length() != 10)
    {
        return false;
    }

    for (char c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

int timeToSecond(string s)
{
    return ((s[0] - '0') * 36000 + (s[1] - '0') * 3600 + (s[3] - '0') * 600 + (s[4] - '0') * 60 + (s[6] - '0') * 10 + s[7] - '0');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int totalCalls = 0;
    string command, fromNumber, toNumber, fromTime, toTime;

    cin >> command;
    while (command != "#")
    {
        totalCalls++;

        cin >> fromNumber;
        numOfCalls[fromNumber]++;

        cin >> toNumber;

        // Date
        cin >> command;

        if (check)
            check = check && isPhonenumber(fromNumber) && isPhonenumber(toNumber);

        // Duration of call
        cin >> fromTime;
        cin >> toTime;
        totalTimeOfCalls[fromNumber] += timeToSecond(toTime) - timeToSecond(fromTime);

        cin >> command;
    }

    cin >> command;
    while (command != "#")
    {
        if (command == "?check_phone_number")
        {
            cout << (check ? 1 : 0) << endl;
        }
        else if (command == "?number_calls_from")
        {
            cin >> command;
            cout << numOfCalls[command] << endl;
        }
        else if (command == "?number_total_calls")
        {
            cout << totalCalls << endl;
        }
        else if (command == "?count_time_calls_from")
        {
            cin >> command;
            cout << totalTimeOfCalls[command] << endl;
        }

        cin >> command;
    }

    return 0;
}