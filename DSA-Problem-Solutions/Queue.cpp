#include <iostream>
using namespace std;

class Queue {
  static const int MAX_SIZE = 100;
  int front;
  int rear;
  int arr[MAX_SIZE];

public:
  Queue() {
    front = -1;
    rear = -1;
  }
  bool isFull() { return (rear == MAX_SIZE - 1); }
  void enqueue(int x) {
    if (!isFull()) {
      arr[++rear] = x;
    } else
      cout << "Queue is full.Cannot insert." << endl;
  }
  void dequeue() {
    if (!isEmpty()) {
      front++;
    } else
      cout << "Queue is empty.Can't delete" << endl;
  }

  int peek() {
    if (!isEmpty()) {
      return arr[front];
    } else {
      cout << "Queue is empty.Can't peek" << endl;
      return -1;
    }
  }
  int getSize() { return (rear - front + 1); }
  bool isEmpty() { return (front == rear); }
  void display() {
    for(int i = front+1; i <= rear; i++){
      cout << arr[i] << " ";
    }
    cout<<endl;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.display();
  q.dequeue();
  q.display();
  return 0;
}