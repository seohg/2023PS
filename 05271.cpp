/* 2023.05.27 백준 9012 -  괄호*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int T;
  stack<char> s;
  bool flag = true;
  cin >> T;
  while (T--) {
    string str = "";
    flag = true;
    s = stack<char>();
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '(') {
        s.push('(');
      } else if (str[i] == ')') {
        if (!s.empty()) {
          s.pop();
        } else {
          flag = false;
          break;
        }
      }
    }
    if (!s.empty()) {
      flag = false;
    }
    if (flag == true) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}