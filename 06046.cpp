/* 2023.06.04 백준 1927 -  최소 힙 */
#include <iostream>
#include <queue>
#include <stdio.h>
#include <functional>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
	int N;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (q.empty()) {
				cout << "0"<<"\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}