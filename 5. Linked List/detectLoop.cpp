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

bool detectLoop(Node* head){
    if(head == NULL)
    return false;

    map<Node*, bool> visited; 
    Node* temp = head;

    while(temp != NULL){

        // loop present
        if(visited[temp] == true)
        return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floydCycleDetection(Node* head){
    if(head == NULL)
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast->next != NULL)
        fast = fast->next;

        slow = slow->next;
        
        if(slow == fast)
        return  slow;
    }
    return NULL;
}

// Get starting node of
Node* getStartingNode(Node* head){
    if(head == NULL)
    return NULL;

    Node* intersection = floydCycleDetection(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head == NULL)
    return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main()
{ 
    Node* tail = NULL;

    // insert in empty list
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    print(tail);

    cout<< "Map method to detect cycle: "<<detectLoop(tail) <<endl;
    cout<< "Floyd cycle detection present at: "<< floydCycleDetection(tail)->data <<endl;
    removeLoop(tail);
    print(tail);
    
    return 0;
}