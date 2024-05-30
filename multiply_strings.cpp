#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string singleMulti(string s, int a, int offset) {
    int c = 0;

    reverse(s.begin(), s.end());

    for (auto& i : s)
    {
        int tmp = a * (i - 48) + c;

        i = tmp % 10 + 48;
        c = tmp / 10;
    }

    while (c)
    {
        s.push_back(c % 10 + 48);
        c /= 10;
    }

    for (int i = 0; i < offset; i++)
    {
        s = "0" + s;
    }

    return s;
}

string multiply(string s, string t) {
    if (s == "0" || t == "0")
    {
        return "0";
    }


    vector<string> r;

    int sz = t.size();
    for (int i = sz - 1; i > 0; i--)
    {
        r.push_back(singleMulti(s, t[i] - 48, sz - 1 - i));
    }

    string tmp = singleMulti(s, t[0] - 48, sz - 1);
    r.push_back(tmp);

    // Sum
    int len = tmp.size(), c = 0;
    string res = "";

    sz = r.size();
    for (int i = 0; i < len; i++)
    {
        int s = 0;

        for (int j = 0; j < sz; j++)
        {
            if (r[j].size() > i)
            {
                s += r[j][i] - 48;
            }
        }
        s += c;

        res.push_back(s % 10 + 48);
        c = s / 10;
    }

    while (c)
    {
        res += c % 10 + 48;
        c /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    cout << multiply(s1, s2);

    return 0;
}