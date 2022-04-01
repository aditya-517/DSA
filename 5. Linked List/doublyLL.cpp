#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for "<<value<<endl;

    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl; 
}

int getLength(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node* &head, Node* &tail, int d){

    // If empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else{
    Node* newNode = new Node(d);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){

    // if list is empty
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else{
        Node *newNode = new Node(d);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }  
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){

    //insert at start
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteNode(Node* &head, int position){

    // deleting first node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    // deleting any middle node or last node

    Node* curr = head;
    Node* prev = NULL;

    int cnt = 1;
    while(cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

int main()
{ 
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 15);
    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 3, 99);
    print(head);

    deleteNode(head, 3);
    print(head);

    cout<< getLength(head) << endl;


    return 0;
}