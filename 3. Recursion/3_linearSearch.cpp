#include<bits/stdc++.h>
using namespace std;

bool linSearch(int *arr, int n, int key){

    // base case
    if(n == 0)
    return false;

    if(arr[0] == key)
    return true;

    return linSearch(arr+1, n-1, key);
}

int main()
{ 
    int arr[] = {2,4,6,8,7};
    int n = 5, key = 88;

    cout<< linSearch(arr, n, key);
    return 0;
}