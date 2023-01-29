/* 2023.01.30 백준 2644번 촌수계산 */
#include <iostream>
#include <queue>
using namespace std;

int N, M, p1, p2;
int cnt = 0;
int arr[101][101] = {0};
int visited[101] = {0};
int depth[101] = {0};
queue<int> q;

void bfs(int start){
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    start = q.front();
    q.pop();

    for(int i=1; i<=N; i++){
      if(arr[start][i] == 1 && visited[i] == 0){
        q.push(i);
        visited[i] = true;
        depth[i] = depth[start] + 1;
      }
    }
  }
}

int main(){
  
  cin >> N;
  cin >> p1 >> p2;
  cin >> M;
  for(int i=0;i<M;i++){
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
  }
  bfs(p1);
  if(depth[p2] == 0){
    cout<< -1;
  }else{
    cout<<depth[p2];
  }
}