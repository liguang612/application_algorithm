#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  stack<char> st;
  string str;

  cin >> str;

  for (char c : str)
  {
    switch (c)
    {
    case '(':
    case '[':
    case '{':
      st.push(c);
      break;
    case ')':
      if (st.empty() || st.top() != '(') {
        cout << 0;
        return 0;
      }
      else
        st.pop();
      break;
    case ']':
      if (st.empty() || st.top() != '[') {
        cout << 0;
        return 0;
      }
      else
        st.pop();
      break;
    case '}':
      if (st.empty() || st.top() != '{') {
        cout << 0;
        return 0;
      }
      else
        st.pop();
      break;

    default:
      break;
    }
  }
  cout << st.empty();

  return 0;
}