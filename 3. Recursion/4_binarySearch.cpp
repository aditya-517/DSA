#include<bits/stdc++.h>
using namespace std;

bool binSearch(int *arr, int key, int s, int e){
    int mid = s + (e-s)/2;

    // base case
    if(s>e)
    return false;

    if(arr[mid] == key)
    return true;

    if(arr[mid] > key)      // search in left part
    return binSearch(arr, key, s, mid-1);

    else                    // search right part
    return binSearch(arr, key, mid+1, e);

}

int main()
{ 
    int arr[] = {2,4,6,7,8,9,10,12,23,24,25};
    
    cout<< binSearch(arr, 456, 0, 10);
    return 0;
}