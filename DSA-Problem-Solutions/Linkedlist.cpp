#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList{
  Node* head;
public:
  LinkedList(){
    head = NULL;
  }
  void insertBeg(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
  void insertEnd(int value){
    Node* newNode = new Node(value);
    if(head == NULL){
      head = newNode;
      return;
    }
    Node* temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
  }
  

};

