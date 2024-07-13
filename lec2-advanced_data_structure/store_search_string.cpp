#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> database;

int main() {
  // freopen("input.txt", "r", stdin);

  string command;

  cin >> command;
  while (command != "*")
  {
    database.insert(command);
    cin >> command;
  }

  cin >> command;
  while (command != "***")
  {
    if (command == "find")
    {
      cin >> command;
      cout << (database.find(command) != database.end()) << endl;
    }
    else {
      cin >> command;
      cout << (database.insert(command).second) << endl;
    }

    cin >> command;
  }

  return 0;
}