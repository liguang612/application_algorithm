#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_phonenumber(string s) {
    if (s.length() != 10)
    {
        return false;
    }
    
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int string_to_second(string s) {
    // return ((s[0] - 48) * 10 + s[1] - 48) * 3600 + ((s[3] - 48) * 10 + s[4] - 48) * 60 + (s[6] - 48) * 10 + s[7] - 48;
    return s[0] * 36000 + s[1] * 3600 + s[3] * 600 + s[4] * 60 + s[6] * 10 + s[7] - 1933008;
}

typedef struct property {
    int total_call;
    int total_time;
};

int main() {
    bool check = true;
    int _duration, total_call = 0;
    string command, date, from_number, from_time, to_number, to_time;
    unordered_map<string, property> properties;

    cin >> command;
    while (command != "#")
    {
        cin >> from_number; // from_number;
        if (check)
        {
            check = check && is_phonenumber(from_number);
        }
        ++total_call;

        ++(properties[from_number].total_call); // total call of number

        cin >> to_number;
        if (check)
        {
            check = check && is_phonenumber(to_number);
        }
        
        cin >> date;
        cin >> from_time;
        cin >> to_time;

        properties[from_number].total_time += string_to_second(to_time) - string_to_second(from_time);

        cin >> command; // re-command
    }

    cin >> command;
    while (command != "#")
    {
        if (command == "?check_phone_number")
        {
            cout << check << endl;
        }
        else if (command == "?number_calls_from")
        {
            cin >> command;

            cout << properties[command].total_call << endl;
        }
        else if (command == "?number_total_calls")
        {
            cout << total_call << endl;
        }
        else
        {
            cin >> command;

            cout << properties[command].total_time << endl;
        }
    }
    
    return 0;
}