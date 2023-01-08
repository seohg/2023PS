/* 2023.01.04 백준 25305번 커트라인 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int arr[1001];
  int N, k;
  
  cin >> N >> k;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr, arr+N,greater<>());
  cout<<arr[k-1];
}