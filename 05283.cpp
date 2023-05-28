/* 2023.05.28 백준 17298 -  오큰수 */
#include <iostream>
#include <stack>
using namespace std;
int arr[1000001] = {0};
int result[1000001] = {0};
stack<int> s;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top() <= arr[i]){
      s.pop();
    }
    if(s.empty()) result[i] = -1;
    else result[i] = s.top();

    s.push(arr[i]);
  }
  for(int i=0;i<n;i++){
    cout<<result[i]<<" ";
  }
  return 0;
}