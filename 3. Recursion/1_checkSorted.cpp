#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size){

    // Base case
    if(size==0 || size==1)
    return true;

    if(arr[0] > arr[1])
    return false;

    return isSorted(arr+1, size-1);
}

int main()
{ 
    int arr[] = {2,4,6,8,7};
    int n = 5;

    cout<< isSorted(arr, n);
    return 0;
}