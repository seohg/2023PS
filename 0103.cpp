/* 2023.01.03 백준 2566번 최댓값 */
#include <iostream>
using namespace std;

int main(){
  int arr[10][10] = {0};
  int maxValue=-1, r, c;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin>>arr[i][j];
      if(arr[i][j] > maxValue){
        maxValue = arr[i][j];
        r = i+1;
        c = j+1;
      }
    }
  }
  cout<<maxValue<<"\n";
  cout<<r<<" "<<c;
}