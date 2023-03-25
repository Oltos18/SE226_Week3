#include<iostream>
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

    void push(int);
    int pop();
    Node* top();
    bool isEmpty();
    int size();
};

void LinkedList::push(int x) {
    if (node_count == 0) {
        head = new Node(x, nullptr);
        tail = head;
        node_count++;
    } else {
        Node* temp = new Node(x, nullptr);
        temp->next=tail;
        tail=temp;
        node_count++;

    }
}
int LinkedList::pop(){
    if(node_count==0){
        cout<<"There is no item in the Stack"<<endl;
        return -1;
    }
    else{
        Node* temp = tail;
        tail=tail->next;
        delete(temp);
        node_count--;
    }
}
Node* LinkedList::top() {
    if (node_count==0){
        return nullptr;
    }
    else{
        return tail;
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
    linkedList.pop();

    linkedList.push(5);
    linkedList.push(7);
    linkedList.push(9);
    linkedList.push(11);
    linkedList.push(13);

    cout<<"size is "<<linkedList.size()<<endl;
    cout<<linkedList.isEmpty()<<endl;

    linkedList.pop();
    cout<<"top data is "<<linkedList.top()->data<<endl;
    linkedList.pop();
    cout<<"top data is "<<linkedList.top()->data<<endl;
    cout<<"size is "<<linkedList.size();

    return 0;
}