#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct node {
    int start;
    int end;
    int value;
    node* left;
    node* right;
};

int* arr;

int init(node* n, int start, int end) {
    n->start = start;
    n->end = end;
    if (start == end)
    {
        n->left = n->right = NULL;
        return (n->value = arr[start]);
    }
    n->left = new node;
    n->right = new node;
    n->value = max(init(n->left, start, (start + end) / 2), init(n->right, (start + end) / 2 + 1, end));

    return n->value;
}

void display(node* n) {


    if (n->left == NULL && n->right == NULL)
    {
        
    }
    
}

int get_max(node* n, int start, int end) {
    if (start == n->start && end == n->end)
    {
        return n->value;
    }

    int middle = (n->start + n->end) / 2;

    if (end <= middle)
    {
        return get_max(n->left, start, end);
    }
    if (start > middle)
    {
        return get_max(n->right, start, end);
    }
    return max(get_max(n->left, start, middle), get_max(n->right, middle + 1, end));
}

void update(node* n, int pos, int value) {
    int middle = (n->start + n->end) / 2;

    if (n->start == n->end)
    {
        n->value = value;
    }
    else if (pos <= middle)
    {
        update(n->left, pos, value);
        n->value = max(n->left->value, n->right->value);
    }
    else {
        update(n->right, pos, value);
        n->value = max(n->left->value, n->right->value);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int a, b, m, n;
    node* head = new node;
    string command;

    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(head, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> command >> a >> b;
        if (command == "get-max")
        {
            cout << get_max(head, a - 1, b - 1) << endl;
        } else {
            update(head, a - 1, b);
            // display(head);
        }
    }

    return 0;
}