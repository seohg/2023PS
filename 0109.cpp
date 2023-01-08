
/* 2023.01.09 백준 25501번 재귀의 귀재 */
#include <cstring>
#include <iostream>
using namespace std;

int T, S, cnt = 0;

int recursion(const char *s, int l, int r) {
	cnt++;
	if (l >= r)
		return 1;
	else if (s[l] != s[r])
		return 0;
	else
		return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		char str[1001];
		cin >> str;
		cout << isPalindrome(str) << " " << cnt << "\n";
	}
}