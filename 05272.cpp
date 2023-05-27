/* 2023.05.27 백준 4949 -  균형잡힌세상 */
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
  stack<char> s;
  char c;
  char t;
  bool tf = true;
  
  while(true){
    string str;
    while(true){
      c = getchar();
      if(c == '.'){
        break;
      }
      if(c!='\n'){
        str +=c;
      }
      
    }
  

  if(str==""){
    break;
  }
  for(int i=0; i<str.size();++i){
    
    if(str[i]=='('||str[i]=='['){
      s.push(str[i]);
      
    }else if(str[i]==')'){ 
      if(s.empty()){
        tf = false;
        break;
      }else if(s.top()=='['){
        tf = false;
        break;
      }else if(s.top()=='('){
        s.pop();
      }else{
        tf = false;
        break;
      }
    }else if(str[i]==']'){
      if(s.empty()){
        tf = false;
        break;
      }else if(s.top()=='('){
        tf = false;
        break;
      }else if(s.top()=='['){
        s.pop();
      }else{
        tf = false;
        break;
      }
      
    }
  }
  
  if(!s.empty()){
    tf = false;
  }
  if(tf == false){
      printf("no\n");
  }else{
      printf("yes\n");
  }
  tf = true;
  while(!s.empty()){
    s.pop();
  }
 }
}