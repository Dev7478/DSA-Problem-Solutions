#include <iostream>
using namespace std;

class Stack {
  static const int MAX = 100;
  int top;
  int arr[MAX];

public:
  Stack() { top = -1; }
  bool isFull() { return top == MAX - 1; }
  bool push(int x) {
    if (!isFull()) {
      arr[++top] = x;
      return true;
    }
    return false;
  }
  int pop() {
    if (!isEmpty()) {
      return arr[top--];
    }
    return top;
  }
  int peek() {
    if (!isEmpty())
      return arr[top];
    return -1;
  }
  bool isEmpty() { return top == -1; }
  void display() {
    for (int i = top; i >= 0; i--)
      cout << arr[i] << " ";
  }
};

int main() {
  Stack s;
  int num;
  cout<<endl;
  cout<<"1.isFull"<<endl;
  cout<<"2.push"<<endl;
  cout<<"3.pop"<<endl;
  cout<<"4.peek"<<endl;
  cout<<"5.isEmpty"<<endl;
  cout<<"6.display"<<endl;
  cout<<"7.exit"<<endl;
  cout<<endl;
  while(true){
    cout<<"Enter your choice: ";
    cin>>num;
    switch(num){
      case 1:
        if(s.isFull())
          cout<<"Stack is full"<<endl;
        else
          cout<<"Stack is not full"<<endl;
        break;
      case 2:
        int x;
        cout<<"Enter the element to be pushed: ";
        cin>>x;
        if(s.push(x))
          cout<<"Element pushed"<<endl;
        else
          cout<<"Stack is full"<<endl;
        break;
      case 3:
        cout<<"Popped element: "<<s.pop()<<endl;
        break;
      case 4:
        cout<<"Top element: "<<s.peek()<<endl;
        break;
      case 5:
        if(s.isEmpty())
          cout<<"Stack is empty"<<endl;
        else
          cout<<"Stack is not empty"<<endl;
        break;
      case 6:
        cout<<"Stack: ";
        s.display();
        cout<<endl;
        break;
      case 7:
        exit(0);
      default:
        cout<<"Invalid choice"<<endl;
        break;
    }
  }
  return 0;
}