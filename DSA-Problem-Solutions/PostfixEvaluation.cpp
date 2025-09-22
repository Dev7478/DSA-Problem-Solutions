#include<iostream>
#include "Stack.cpp"
using namespace std;

int evaluation(string exp){
  Stack s;
  for(int i = 0; i < exp.length(); i++){
    if(exp[i] >= '0' && exp[i] <= '9'){
      s.push(exp[i] - '0');
    }
    else{
      int x = s.pop();
      int y = s.pop();
      switch(exp[i]){
        case '+':
          s.push(y + x);
          break;
        case '-':
          s.push(y - x);
          break;
        case '*':
          s.push(y * x);
          break;
        case '/': 
          s.push(y / x);
          break;
      }
    }
  }
  return s.pop();
}
int main(){
  string exp;
  cout<<"Enter the postfix expression: ";
  cin>>exp;
  cout<<"Evaluation of the postfix expression: "<<evaluation(exp)<<endl;
  return 0;
}