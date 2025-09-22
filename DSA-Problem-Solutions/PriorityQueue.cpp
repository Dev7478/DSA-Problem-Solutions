#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int d, int p) {
        Node* temp = new Node;
        temp->data = d;
        temp->priority = p;
        temp->next = nullptr;

        if (front == nullptr || p < front->priority) {
            temp->next = front;
            front = temp;
        } else {
            Node* start = front;
            while (start->next != nullptr && start->next->priority <= p) {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            cout << "Dequeued item: " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << "\t" << temp->priority << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    PriorityQueue pq;
    
    pq.enqueue(3, 2);
    pq.enqueue(5, 1);
    pq.enqueue(8, 6);
    pq.enqueue(9, 5);
    pq.enqueue(1, 3);
    
    pq.display();

    pq.dequeue();
    pq.dequeue();

    pq.display();

    return 0;
}