/* 2023.06.04 백준 1966 -  프린터 큐*/
#include <iostream>
#include <queue>
using namespace std;


int main(){
  int t, n, m, tmp, count=0;
  cin>>t;
  while(t--){
    count=0;
    queue<pair<int, int>>q;
    priority_queue<int> pq;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
      cin>>tmp;
      q.push(make_pair(i, tmp));
      pq.push(tmp);
    }

    while(!q.empty()){
      int idx = q.front().first;
      int val = q.front().second;
      q.pop();
      if(val==pq.top()){
        pq.pop();
        count++;
        if(idx == m){
          cout<< count <<"\n";
          break;
        }
      }else{
        q.push(make_pair(idx, val));
      }
    }
  }
  return 0;
}