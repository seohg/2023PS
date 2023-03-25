/* 2023.03.25 프로그래머스 연습문제 - 리코쳇 로봇 */
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Robot{
    pair<int, int> pos;
    int cnt;
};

char map[101][101];
bool visited[101][101] = {false, };

queue<Robot> q;
int startX, startY;
int targetX, targetY;
int N, M, minV = -1;
bool flag = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

Robot move(int r, int c, int dir, int cur) {
    Robot moved;
   
	while (c + dx[dir] >=0
           && c + dx[dir] < M
           && r + dy[dir] >= 0
           && r + dy[dir] < N
           && map[r + dy[dir]][c + dx[dir]] != 'D') {
		c += dx[dir];
		r += dy[dir];
	}
     moved.pos.first = r; 
     moved.pos.second = c;
     moved.cnt = cur + 1;
     
    return moved;
}

void bfs(){
    Robot r;
    r.pos.first = startY;
    r.pos.second = startX;
    r.cnt = 0;
    
    q.push(r);
    visited[startY][startX] = true;
    
    while(!q.empty()){
        int cur_y = q.front().pos.first;
        int cur_x = q.front().pos.second;
        int cur_cnt = q.front().cnt;
        q.pop();
        
        for(int i=0;i<4;i++){
            Robot moved = move(cur_y, cur_x, i, cur_cnt);
            
            if(moved.pos.first == targetY && moved.pos.second == targetX){
                minV = moved.cnt;
                flag = true;
                break;
            }
            
            if(flag){
                break;
            }
            
            if(!visited[moved.pos.first][moved.pos.second]){
                q.push(moved);
                visited[moved.pos.first][moved.pos.second] = true;
            }
        }
    }
}

int solution(vector<string> board) {
    N = board.size();
    M = board[0].length();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = board[i][j];
            if(board[i][j] == 'R'){
                startY = i;
                startX = j;
            }else if(board[i][j] == 'G'){
                targetY = i;
                targetX = j;
            }
        }
    }
    
    bfs();
    
    return minV;
}