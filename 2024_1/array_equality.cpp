#include <iostream>

using namespace std;

int t, sizeA, sizeB, a[1000], b[1000];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> sizeA;
        cin >> sizeB;

        for (int i = 0; i < sizeA; i++)
            cin >> a[i];

        for (int i = 0; i < sizeB; i++)
            cin >> b[i];

        if (sizeA != sizeB)
        {
            cout << 0 << endl;
            continue;
        }

        bool isEqual = true;
        for (int i = 0; i < sizeA; i++)
        {
            if (a[i] != b[i])
            {
                isEqual = false;
                break;
            }
        }

        cout << (int)isEqual << endl;
    }
    return 0;
}