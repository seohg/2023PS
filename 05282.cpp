/* 2023.05.28 백준 9935 -  문자열 폭발 */
#include <iostream>
using namespace std;

int main(){
  string str, bomb, ans = "";
  
  cin >> str;
  cin >> bomb;

  int idx = bomb.length() - 1;
  
  for(int i=0;i<str.length();i++){
    ans += str[i];
    
    if(ans[ans.length()-1] == bomb[idx]){
      if(bomb.length() <= ans.length()){
        int cnt = 1;
        for(int j = idx - 1; j>=0;j--){
          if(ans[ans.length() -1 - (idx-j)] == bomb[j]){
            cnt++;
          }
        }
        if(cnt == bomb.length()){
          for(int b = 0; b< bomb.length(); b++){
            ans.pop_back();
          }
        }
      }
    }
  }
  if(ans.length()>0){
    cout<<ans<<endl;
  }else{
    cout<<"FRULA"<<endl;
  }
  return 0;
}