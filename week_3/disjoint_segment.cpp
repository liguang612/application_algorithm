#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct line {
    int start;
    int end;
    
    line(int start, int end) : start(start), end(end) {}

    bool conflict(line& other) {
        return (start <= other.end && start >= other.start) || (other.start <= end && other.start >= start);
    }

    bool operator<(line& other) {
        return end < other.end;
    }
} line;

int main() {
    // freopen("input.txt", "r", stdin);

    int a, b, n, res = 0;
    vector<line> lines;
    vector<line> plan;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        lines.push_back(line(a, b));
    }

    sort(lines.begin(), lines.end());

    plan.push_back(lines[0]);
    for (line l : lines)
    {
        if (!l.conflict(*(plan.end() - 1)))
        {
            plan.push_back(l);
        }
    }
    
    cout << plan.size();
    

    return 0;
}