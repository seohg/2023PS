/* 2023.03.06 백준 13460번 구슬탈출2 */
#include <iostream>
#include <queue>
using namespace std;

struct bead {
	int rx, ry;
	int bx, by;
	int cnt;
};

int N, M;
char board[10][10];
bool visited[10][10][10][10];
queue<bead> q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void move(int &x, int &y, int &c, int &dir) {
	while (board[x + dx[dir]][y + dy[dir]] != '#' && board[x][y] != 'O') {
		x += dx[dir];
		y += dy[dir];
		c += 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10)
			break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncnt = cnt + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (board[nbx][nby] == 'O')
				continue;
			if (board[nrx][nry] == 'O') {
				cout << ncnt;
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) {
					nrx -= dx[i], nry -= dy[i];
				} else {
					nbx -= dx[i], nby -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby])
				continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({nrx, nry, nbx, nby, ncnt});
		}
	}
	cout << -1;
}

int main() {
	cin >> N >> M;
	int rx = 0, ry = 0, bx = 0, by = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j];
			if (str[j] == 'R') {
				rx = i;
				ry = j;
			} else if (str[j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	q.push({rx, ry, bx, by, 0});
	visited[rx][ry][bx][by] = true;
	bfs();
}