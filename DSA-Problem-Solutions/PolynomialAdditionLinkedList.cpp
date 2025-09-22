#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
  int coeff;
  int power;
  Node* next;
  Node(int coeff, int power){
    coeff = coeff;
    power = power;
    next = NULL;
  }
};

class Polynomial{
  Node* head;
public:
  Polynomial(){
    head = NULL;
  }
  Polynomial(const Polynomial& p){
    head = NULL;
    Node* temp = p.head;
    while(temp != NULL){
      insert(temp->coeff, temp->power);
      temp = temp->next;
    }
  }
  ~Polynomial(){
    Node* curr = head;
    while(curr){
      Node* temp = curr;;
      curr = curr->next;
      delete temp;
    }
  }
  Polynomial operator=(const Polynomial& p){
    Node* temp = p.head;
    while(temp!=NULL){
      insert(temp->coeff, temp->power);
      temp = temp->next;
    }
    return(*this);
  }
  void insert(int coeff, int power){
    Node* newNode = new Node(coeff, power);
    if(!head){
      head = newNode;
    }
    else{
      Node* curr = head;
      while(curr->next){
        curr = curr->next;
      }
      curr->next = newNode;
    }
  }
  void display(){
    Node* curr = head;
    while(curr){
      if(curr->power==0)
        cout<<curr->coeff;
      else
        cout<<curr->coeff<<"x^"<<curr->power;
      curr = curr->next;
      if(curr){
        if(curr->coeff>0)
          cout<<"+";
      }
    }    
    cout<<endl;
  }
    Polynomial operator+(const Polynomial& p){
      Polynomial result;
      Node* p1 = head;
      Node* p2 = p.head;

      while(p1 && p2){
        if(p1->power == p2->power){
          result.insert(p1->coeff + p2->coeff, p1->power);
          p1 = p1->next;
          p2 = p2->next;
        }
        else if(p1->power > p2->power){
          result.insert(p1->coeff, p1->power);
          p1 = p1->next;
        }
        else{
          result.insert(p2->coeff, p2->power);
          p2 = p2->next;
        }
      }
      while(p1){
        result.insert(p1->coeff, p1->power);
        p1 = p1->next;
      }
      while(p2){
        result.insert(p2->coeff, p2->power);
        p2 = p2->next;
      }
      return result;
    }
};

int main(){
  Polynomial p1, p2, p3;

  p1.insert(3, 2);
  p1.insert(2, 1);
  p1.insert(5, 0);

  p2.insert(8, 1);
  p2.insert(3, 0);

  p3 = p1 + p2;

  cout<<"Polynomial 1: ";
  p1.display();
  cout<<"Polynomial 2: ";
  p2.display();
  cout<<"Resultant Polynomial: ";
  p3.display();

  return 0;
}