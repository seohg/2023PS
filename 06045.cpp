/* 2023.06.04 백준 11279 -  최대 힙 */
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

priority_queue<int> pq;

int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    int x;
    scanf("%d",&x);
    if(x==0){
      if(pq.empty()){
        printf("0\n");
      }else{
        cout<<pq.top()<<"\n";
        pq.pop();
      }
    }else{
      pq.push(x);
    }
  }
  return 0;
}