#include<bits/stdc++.h>
using namespace std;

class kQueue{
    public: 
    int n, k;
    int *front, *rear, *next, *arr;
    int freespot;

    kQueue(int n, int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];

        freespot = 0;
    }

    void enqueue(int data, int qn){
        //check overflow
        if(freespot == -1){
            cout<<"No free space"<<endl;
            return;
        }

        // find first free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check if first val in queue
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            // link new element to prev element
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn){
        //underflow
        if(front[qn-1]==-1){
        cout<<"Queue underflow"<<endl;
        return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // update front
        front[qn-1] = next[index];

        // update freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{ 
    kQueue q(10,2);
    q.enqueue(10,1);
    q.enqueue(20,1);
    q.enqueue(70,2);
    q.enqueue(80,2);
    q.enqueue(30,1);
    cout << q.dequeue(1) <<endl;
    cout << q.dequeue(2) <<endl;
    cout << q.dequeue(2) <<endl;
    return 0;
}