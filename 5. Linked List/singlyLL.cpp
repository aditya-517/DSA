#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        //Memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed for "<< value<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    
    // create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    // insert at head
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    // Move temp to pos-1
    while(cnt != position-1){
        temp = temp->next;
        cnt++;
    }

    // insert at tail
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, int position){

    // deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
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

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// This is a linked list and
int main()
{ 
    // creating a new node
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head pointed to node
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 15);
    insertAtHead(head, 20);


    insertAtTail(tail, 25);
    insertAtTail(tail, 50);


    insertAtPosition(head, tail, 3, 99);

    print(head);

    cout<<"Head : " << head->data << endl;
    cout<<"Tail : " << tail->data << endl;

    deleteNode(head, 3);

    print(head);
    
    return 0;
}