#include <iostream>
#include <vector>

using namespace std;

bool married_staff[10001], married_tasks[10001];
int N, M, pairs = 0;
vector<int> staffs[10001], tasks[10001]; // staff vector store the tasks that staff can do, and otherwise

void engage(int first, int end, bool first_is_task)
{
    int f = -1, e = -1;
    pairs++;

    if (first_is_task)
    {
        married_tasks[first] = married_staff[end] = true;

        for (int i : tasks[first])
        {
            if (!married_staff[i])
            {
                f = i;
                break;
            }
        }
        if (f == -1)
            return;

        for (int i : staffs[end])
        {
            if (!married_tasks[i])
            {
                e = i;
                break;
            }
        }
        if (e == -1)
            return;
    }
    else
    {
        married_tasks[end] = married_staff[first] = true;

        for (int i : staffs[first])
        {
            if (!married_tasks[i])
            {
                f = i;
                break;
            }
        }
        if (f == -1)
            return;

        for (int i : tasks[end])
        {
            if (!married_staff[i])
            {
                e = i;
                break;
            }
        }
        if (e == -1)
            return;
    }

    engage(f, e, !first_is_task);
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int a, b;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> a;

        for (int j = 0; j < a; j++)
        {
            cin >> b;
            tasks[i].push_back(b);
            staffs[b].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (!married_tasks[i])
        { // If found a task hasn't been married
            for (int j : tasks[i])
            {
                if (!married_staff[j])
                { // Let's find a staff for it
                    engage(i, j, true);
                    break;
                }
            }
        }
    }

    cout << pairs;

    return 0;
}
