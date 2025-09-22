#include<iostream>
#include <string>
#include "Stack.cpp"
using namespace std;

int get_precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
string infix_to_postfix(string exp) {
  Stack s;
  string result;
  int i=0;  
  while(exp[i]!='\0'){
    if(isOperand(exp[i])){
      result+=exp[i];
      i++;
    }
    else if(exp[i]=='('){
      s.push(exp[i]);
      i++;
    }
    else if(exp[i]==')'){
      while(s.peek()!='('){
        result+=s.peek();
        s.pop();
      }
      s.pop();
      i++;
    }
    else{
      while(!s.isEmpty() && (s.peek()!='(') && get_precedence(exp[i])<=get_precedence(s.peek())){
        result+=s.peek();
        s.pop();
      }
      s.push(exp[i]);
      i++;
    }
  }
  while(!(s.isEmpty())){
    result+=s.peek();
    s.pop();
  }
  return result;
}
//     for (int i = 0; i < exp.length(); i++) {
//         char c = exp[i];
//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//             result += c;
//         else if (c == '(')
//             s.push(c);
//         else if (c == ')') {
//             while (!s.empty() && s.top() != '(') {
//                 result += s.top();
//                 s.pop();
//             }
//             s.pop();
//         } else {
//             while (!s.empty() && get_precedence(c) <= get_precedence(s.top())) {
//                 result += s.top();
//                 s.pop();
//             }
//             s.push(c);
//         }
//     }
//     while (!s.empty()) {
//         result += s.top();
//         s.pop();
//     }
//     return result;
// }

int main() {
    string exp;
    cout << "Enter the infix expression: ";
    cin >> exp;
    cout << "Infix expression: " << exp << endl;
    cout << "Postfix expression: " << infix_to_postfix(exp) << endl;
    return 0;
}