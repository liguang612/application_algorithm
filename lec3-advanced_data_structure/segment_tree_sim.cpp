#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct node {
  int id;
  int left;
  int right;
  int max_value;
  node* l_child;
  node* r_child;

  node() {};
  node(int id, int left, int right) : id(id), left(left), right(right) {
    l_child = r_child = NULL;
  }
} node;

int arr[100001], n;
node* tree;

int preprocessing(node* tree) {
  if (tree->left == tree->right) return tree->max_value = arr[tree->left];
  tree->l_child = new node(2 * tree->id, tree->left, (tree->left + tree->right) / 2);
  tree->r_child = new node(2 * tree->id + 1, (tree->left + tree->right) / 2 + 1, tree->right);

  return tree->max_value = max(preprocessing(tree->l_child), preprocessing(tree->r_child));
}

void display(node* tree) {
  if (tree == NULL) return;

  cout << tree->id << "[" << tree->left << ", " << tree->right << "] :" << tree->max_value << '\n';
  display(tree->l_child);
  display(tree->r_child);
}

int getmax(node* tree, int a, int b) {
  if (tree->left > b || tree->right < a) return -100000;
  if (tree->left >= a && tree->right <= b) return tree->max_value;

  return max(getmax(tree->l_child, a, b), getmax(tree->r_child, a, b));
}

int update(node* tree, int i, int v) {
  if (tree->left > i || tree->right < i) return tree->max_value;
  if (tree->left == tree->right)
  {
    tree->max_value = v;
    return tree->max_value;
  }

  return tree->max_value = max(update(tree->l_child, i, v), update(tree->r_child, i, v));
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  tree = new node(1, 1, n);
  preprocessing(tree);

  // display(tree);
  // return 0;

  int i, k, v;
  string command;

  cin >> k;
  for (int j = 0; j < k; j++)
  {
    cin >> command >> i >> v;
    if (command == "update") {
      update(tree, i, v);
    }
    else {
      cout << getmax(tree, i, v) << '\n';
    }
  }

  return 0;
}