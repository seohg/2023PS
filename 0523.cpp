/* 2023.05.22 백준 10773 - 제로 */
#include <iostream>
#include <stack>
using namespace std;

int main(){
  int K, sum = 0;
  stack<int> s;
  cin >> K;
  while(K--){
    int N;
    cin >> N;
    if(N == 0){
      s.pop();
    }else{
      s.push(N);
    }
  }
  while(!s.empty()){
    sum += s.top();
    s.pop();
  }
  cout<<sum;
  
}