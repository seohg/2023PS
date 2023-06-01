/* 2023.06.01 백준 2164 -  카드2*/
#include <iostream>
#include <queue>

using namespace std;
int main(){
  int N;
  queue<int> q;

  scanf("%d", &N);
  for(int i=1;i<=N;i++){
    q.push(i);
  }
  while(q.size()>1){
    q.pop();
    int tmp = q.front();
    q.pop();
    q.push(tmp);
  }
  cout<<q.front()<<endl;
}
