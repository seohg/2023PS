/* 2023.06.04 백준 1021 -  회전하는 큐 */
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(){
  int N, M, L, R, cnt =0;
  deque<int> dq;

  cin>> N >> M;
  for(int i=1;i<=N;i++){
    dq.push_back(i);
  }
  while(M--){
    int tmp;
    cin>>tmp;
    for(int i=0;i<dq.size();i++){
      if(dq[i] == tmp){
        L = i;
        R = dq.size()-i;
        break;
      }
    }
    if(L<=R){
      while(dq.front()!=tmp){
        dq.push_back(dq.front());
        dq.pop_front();
        cnt++;
      }
      dq.pop_front();
    }else{
      while(dq.back()!=tmp){
        dq.push_front(dq.back());
        dq.pop_back();
        cnt++;
      }
      dq.pop_back();
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}