/* 2023.03.25 프로그래머스 연습문제 - 미로 탈출 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int r, c;
};

struct Pos{
    int r, c;
    int cnt;
};

char map[101][101];
bool visited[101][101] = {false, };
int M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool findLev = false;
bool findExit = false;
Point start, lev, door;
queue<Pos> q1;
queue<Pos> q2;


int bfs1(){
    Pos tmp;
    tmp.r = start.r;
    tmp.c = start.c;
    tmp.cnt = 0;
    q1.push(tmp);
    visited[start.r][start.c] = true;
    
    while(!q1.empty()){
        Pos cur = q1.front();
        q1.pop();
        
        for(int i=0;i<4;i++){
            int ny = cur.r + dy[i];
            int nx = cur.c + dx[i];
            int ncnt = cur.cnt + 1;
            
            if(ny == lev.r && nx == lev.c){
                findLev = true;
                break;
            }
            
            if(ny<0||ny>=M||nx<0||nx>=N){
                continue;
            }
            
            if(!visited[ny][nx] && (map[ny][nx] == 'E' || map[ny][nx] == 'O')){
                Pos next;
                next.r = ny;
                next.c = nx;
                next.cnt = ncnt;
                q1.push(next);
                visited[ny][nx] = true;
            }
        }
        if(findLev){
            return cur.cnt + 1;
        }
    }
    
    return -1;
}

int bfs2(){
    Pos tmp;
    tmp.r = lev.r;
    tmp.c = lev.c;
    tmp.cnt = 0;
    
    q2.push(tmp);
    visited[lev.r][lev.c] = true;
    
    while(!q2.empty()){
        Pos cur = q2.front();
        q2.pop();
        
        for(int i=0;i<4;i++){
            int ny = cur.r + dy[i];
            int nx = cur.c + dx[i];
            int ncnt = cur.cnt + 1;
            
            if(ny == door.r && nx == door.c){
                findExit = true;
                break;
            }
            
            if(ny<0||ny>=M||nx<0||nx>=N){
                continue;
            }
            
            if(!visited[ny][nx] && (map[ny][nx] == 'S' || map[ny][nx] == 'O')){
                Pos next;
                next.r = ny;
                next.c = nx;
                next.cnt = ncnt;
                q2.push(next);
                visited[ny][nx] = true;
            }
        }
        if(findExit){
            return cur.cnt + 1;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = -1;
    
    M = maps.size();
    N = maps[0].length();
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            map[i][j] = maps[i][j];
            if(map[i][j] == 'S'){
                start.r = i;
                start.c = j;
            }else if(map[i][j] == 'L'){
                lev.r = i;
                lev.c = j;
            }else if(map[i][j] == 'E'){
                door.r = i;
                door.c = j;
            }
        }
    }
    answer = bfs1();
    
    if(answer == -1){
        return -1;
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            visited[i][j] = false;
        }
    }
    
    int _bfs2 = bfs2();
    if(_bfs2 == -1){    
        return -1;
    }
    answer += _bfs2;
    return answer;
}