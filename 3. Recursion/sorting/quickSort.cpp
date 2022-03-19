#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    // Count elements greater than pivot
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot)
        cnt++;
    }

    // Place pivot to correct position
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex], arr[s]);

    // Sort left and right part of pivot
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex)
        swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    // base case
    if(s>=e)
    return;

    // Partition the array
    int p = partition(arr, s, e);

    // Sort the left part
    quickSort(arr, s, p-1);

    // Sort the right part
    quickSort(arr, p+1, e);

}
int main()
{ 
    int arr[5] = {3,2,4,5,1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n = 5; 

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    return 0;
}