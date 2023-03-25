#include <iostream>
#include <new>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int tempdata, Node* tempnext){
        data=tempdata;
        next=tempnext;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int node_count=0;

    void enqueue(int);
    int dequeue();
    Node* top();
    bool isEmpty();
    int size();
};

void LinkedList::enqueue(int x) {
    if (node_count == 0) {
        head = new Node(x, nullptr);
        tail = head;
        node_count++;
    } else {
        Node* temp = new Node(x, nullptr);
        tail->next = temp;
        tail=temp;
        node_count++;

    }
}
int LinkedList::dequeue(){
    if(node_count==0){
        cout<<"There is no item in the Queue"<<endl;
        return -1;
    }
    else{
        Node* temp = head;
        head=head->next;
        delete(temp);
        node_count--;
    }
}
Node* LinkedList::top() {
    if (node_count==0){
        return nullptr;
    }
    else{
        return head;
    }
}
bool LinkedList::isEmpty() {
    if(node_count==0){
        return true;
    }
    else{
        return false;
    }
}
int LinkedList::size() {
    return node_count;
}


int main() {
    class LinkedList linkedList;

    cout<<"size is "<<linkedList.size()<<endl;
    cout<<linkedList.isEmpty()<<endl;
    linkedList.dequeue();

    linkedList.enqueue(5);
    linkedList.enqueue(7);
    linkedList.enqueue(9);
    linkedList.enqueue(11);
    linkedList.enqueue(13);

    cout<<"size is "<<linkedList.size()<<endl;
    cout<<linkedList.isEmpty()<<endl;

    linkedList.dequeue();
    cout<<"top data is "<<linkedList.top()->data<<endl;
    linkedList.dequeue();
    cout<<"top data is "<<linkedList.top()->data<<endl;
    cout<<"size is "<<linkedList.size();

    return 0;
}