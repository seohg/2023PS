/* 2023.05.28 백준 17299 -  오등 큰수*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
  int N;
  int arr[1000001];
  int cnt[1000001] = {0};
  int ans[1000001];
  stack<int> s;
  
  cin>> N;
  
  for(int i=0;i<N;i++){
    cin>> arr[i];
    cnt[arr[i]]++;
  }
  
  for(int i=N-1;i>=0;i--){
    int idx = arr[i];
    int count = cnt[idx];

    while(!s.empty()){
      int topIdx = arr[s.top()];
      int topCount = cnt[topIdx];

      if(count >= topCount) s.pop();
      else break;
    }
    
    ans[i] = -1;
    if(!s.empty()) ans[i] = arr[s.top()];
    
    s.push(i);
  }
  
  for(int i=0;i<N;i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}