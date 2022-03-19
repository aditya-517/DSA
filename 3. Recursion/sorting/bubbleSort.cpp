#include<bits/stdc++.h>
using namespace std;

void bubble(int* arr, int n){

    // already sorted
    if(n==0 || n==1)
    return;
    
    // solve for a single case -- put largest element at end
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    // leave the last element as it is in correct place
    bubble(arr, n-1);
}
int main()
{ 
    int arr[] = {4,3,5,7,2,1};
    bubble(arr, 6);

    for(int i:arr)
    cout<<i<<" ";

    return 0;
}