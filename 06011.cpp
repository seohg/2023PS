/* 2023.06.01 백준 18258 -  큐2*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);
  
  int N, tmp;
  string s;
  queue<int> q;
  cin>> N;
  for(int i=0;i<N;i++){
    cin>>s;
    if(s == "push"){
      cin>>tmp;
      q.push(tmp);
    }else if(s == "pop"){
      if(q.empty()){
        cout<<"-1\n"; 
      }else{
        cout<<q.front()<<"\n"; 
        q.pop();
      }
      
    }else if(s == "size"){
      cout<<q.size()<<"\n";
    }else if(s == "empty"){
      cout << q.empty() << '\n';
    }else if(s == "front"){
      if(q.empty()){
        cout<<"-1\n"; 
      }else{
        cout<<q.front()<<"\n"; 
      }
    }else if(s == "back"){
      if(q.empty()){
        cout<<"-1\n"; 
      }else{
        cout<<q.back()<<"\n"; 
      }
    }
  }
}