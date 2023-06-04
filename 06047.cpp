/* 2023.06.04 백준 11286 -  절댓값 힙 */
#include <iostream>
#include <queue>
using namespace std;
struct comp {
	bool operator()(const int &x, const int &y)
	{
    if (abs(x) == abs(y))
			return x > y;
		return abs(x) > abs(y);
	}
};
int main(){
  int N, x;
  priority_queue<int, vector<int>, comp> pq;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>x;
    if(x){
      pq.push(x);
    }else{
      if(pq.empty()){
        cout<<0<<"\n";
      }else{
        cout<<pq.top()<<"\n";
        pq.pop();
      }
      
    }
  }
  return 0;
}