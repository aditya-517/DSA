#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for "<<value<<endl ;
    }
};

void insertNode(Node* &tail, int element, int d){
    // to insert new node after element

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // non empty list
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }
        //element found 
        // curr is the element node

        Node* newNode = new Node(d);
        newNode->next = curr->next;
        curr->next = newNode;

    }
}

void deleteNode(Node* &tail, int value){

    // empty list
    if(tail == NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    else{
        // non empty
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // Single node LL
        if(curr == prev){
            tail = NULL;
        }

        // >=2 node LL
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr; 
    }
}

void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL)
    {
        cout<<"Empty List"<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main()
{ 
    Node* tail = NULL;

    // insert in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 10);
    print(tail);

    deleteNode(tail, 5);
    print(tail);
    
    return 0;
}