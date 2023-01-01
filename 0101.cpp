/* 2023.01.01 백준 25034번 영수증 */
#include <iostream>
using namespace std;

int main() {
  int price, N, sum = 0;
  cin >> price;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    sum += a * b;
  }
  if (price == sum) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}