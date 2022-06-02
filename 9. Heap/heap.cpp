#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++; 
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            
            else
            return;
        }
    }

    void print(){
        for(int i = 1; i<=size; i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"Heap already empty";
            return;
        }
        
        // Copy last node to root
        arr[1] = arr[size];
        size--;

        // Propagate root to it's correct position
        int i=1;
        while(i<size){
            int leftInd = 2*i;
            int rightInd = 2*i + 1;

            if(leftInd<size && arr[i]<arr[leftInd]){
                swap(arr[i], arr[leftInd]);
                i = leftInd;
            }
            else if(rightInd<size && arr[i]<arr[rightInd]){
                swap(arr[i], arr[rightInd]);
                i = rightInd;
            }
            else
            return;
        }
    }
};

void heapify(int arr[], int n, int i){

    // for max heap i is largest
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }

    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        // step 1: swap last node with root
        swap(arr[size], arr[1]);
        size--;

        // heapify root node
        heapify(arr, size, 1);
    }
}

int main()
{ 
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deletefromHeap();
    h.print(); 


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // Heap creation
    // Since leaf nodes are already heap, no need to check for them 
    for(int i = n/2; i>=1; i--){
        heapify(arr, n, i);
    }
    cout<<"Heapified Array: ";
    for(int i=1; i<=n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    heapSort(arr, n);
    cout<<"Sorted Array: ";
    for(int i=1; i<=n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"=== Using Priority Queue ==="<<endl;

    // Max Heap by default
    priority_queue<int> pq;

    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(5);

    cout<<"Top element : "<<pq.top() << endl;
    pq.pop();
    cout<<"Top element : "<<pq.top() << endl;
    cout<<"Size : "<<pq.size() << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(5);

    cout<<"Min Heap" << endl;
    cout<<"Top element : "<<minHeap.top() << endl;
    minHeap.pop();
    cout<<"Top element : "<<minHeap.top() << endl;

    return 0;
}