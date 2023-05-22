/* 2023.05.22 백준 10828 - 스택 */
#include <iostream>
#include <stack>
using namespace std;

int main(){
  int T;
  string str;
  stack<int> s;
  cin>>T;
  while(T--){
    cin>>str;
    if(str == "push"){
      int n;
      cin >> n;
      s.push(n);
    }else if (str == "pop"){
      if(s.empty()){
        cout<<"-1\n";
      }else{
        cout<<s.top()<<"\n";
        s.pop();
      }
    }else if (str == "size"){
      cout<<s.size()<<"\n";
    }else if (str == "empty"){
      if(s.empty()){
        cout<<"1\n";
      }else{
        cout<<"0\n";
      }
    }else if (str == "top"){
      if(s.empty()){
        cout<<"-1\n";
      }else{
        cout<<s.top()<<"\n";
      }
    }
  }
  return 0;
}