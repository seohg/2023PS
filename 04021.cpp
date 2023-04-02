/* 2023.04.01 프로그래머스 연습문제 - 무인도 여행 */

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
bool visited[101][101] = {false};
int map[101][101] = {0};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;


int bfs(int r, int c){
    int ret = 0;
    
    q.push(make_pair(r, c));
    visited[r][c] = true;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        ret += map[y][x];
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= M || ny < 0 || nx < 0 || nx >= N){
                continue;
            }
            
            if(!visited[ny][nx] && map[ny][nx] != 0){
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
        
    } 
    return ret;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;

    M = maps.size();
    N = maps[0].length();
    
    for(int i=0;i<M; i++){
        for(int j=0;j<N;j++){
            if(maps[i][j] == 'X')
                map[i][j] = maps[i][j] - 'X';
            else
                map[i][j] = maps[i][j] - '0';
        }
    }
    
    for(int i=0;i<M; i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && map[i][j] != 0){
                int ret = bfs(i, j);
                if(ret != 0){
                    answer.push_back(ret);
                }
            }
        }
    }
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}