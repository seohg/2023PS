/* 2023.06.04 백준 10866 -  덱 */
#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main(){
  int T,data;
  string s;
  cin>>T;
  while(T--){
    cin>>s;
    if(s=="push_front"){
      cin>>data;
      dq.push_front(data);
    }else if(s=="push_back"){
      cin>>data;
      dq.push_back(data);
    }else if(s=="pop_front"){
      if(dq.empty()){
        cout<<"-1"<<endl;
        continue;
      }
      data=dq.front();
      cout<<data<<endl;
      dq.pop_front();
    }else if(s=="pop_back"){
      if(dq.empty()){
        cout<<"-1"<<endl;
        continue;
      }
      data=dq.back();
      cout<<data<<endl;
      dq.pop_back();
    }else if(s=="size"){
      cout<<dq.size()<<endl;
    }else if(s=="empty"){
       if(dq.empty()){
        cout<<"1"<<endl;
      }else{
        cout<<"0"<<endl;
      }
    }else if(s=="front"){
      if(dq.empty()){
        cout<<"-1"<<endl;
        continue;
      }
      cout<<dq.front()<<endl;
    }else if(s=="back"){
      if(dq.empty()){
        cout<<"-1"<<endl;
        continue;
      }
      cout<<dq.back()<<endl;
    }
  }
}
