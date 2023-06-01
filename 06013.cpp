/* 2023.06.01 백준 11866 -  요세푸스 문제 0*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int n, k;
  queue<int> q;
  queue<int> r; 

  scanf("%d %d",&n,&k);

  for(int i=1;i<=n;i++){
    q.push(i);
  }


  while(r.size()!=n){
    for(int i=1;i<=k;i++){
      if(i!=k){
        int temp = q.front();
        q.pop();
        q.push(temp);
      }else{
        int temp = q.front();
        q.pop();
        r.push(temp);
      }
    }
  }
  

  printf("<");
  for(int i=1;i<=n;i++){
    printf("%d",r.front());
    r.pop();

    if(i!=n){
      printf(", ");
    }else{
      printf(">");
    }
  }
}