#include <iostream>
using namespace std;

int main(){
  int a[101][101] = {0};
  int b[101][101] = {0};
  int n, m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>b[i][j];
      b[i][j] += a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<b[i][j]<<" ";
    }
    cout<<"\n";
  }
}