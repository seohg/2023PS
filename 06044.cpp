/* 2023.06.04 백준 5430 -  AC */
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
  int T, n, tmpN;
  deque<int> dq;
  bool reverse = false, err = false;
  string s, str, tmpStr;
  cin>>T;
  while(T--){
    cin>>s;
    cin>>n;
    cin>>str;
    tmpStr = "";
    reverse = err = false;
    for(int i=0;i<str.length();i++){
      if(isdigit(str[i])){
        tmpStr += str[i];
      }else{
        if(tmpStr!=""){
          dq.push_back(stoi(tmpStr));
          tmpStr = "";
        }
      }
    }
    for(int i=0;i<s.length();i++){
      if(s[i]=='R'){
        reverse = (!reverse);
      }else if(s[i]=='D'){
        if(reverse){
          if(!dq.empty())
            dq.pop_back();
          else{
            err = true;
            break;
          }
        }else{
          if(!dq.empty())
            dq.pop_front();
          else{
            err = true;
            break;
          }
        }
      }
    }
    if(err){
      cout<<"error\n";
    }else{
      cout << '[';
      if (reverse && !dq.empty()) {
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        else if (!reverse&&!dq.empty()){
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
      cout <<"]\n";
      }
      dq.clear();
    }
  return 0;
}