#include<bits/stdc++.h>
using namespace std;

int getsum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main()
{ 
    // char* ch = new char;
    // *ch = 'a';
    // delete ch;
    // cout<<*ch<<endl;

    // Variable size array
    int *arr = new int[5];
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    cout<<getsum(arr, 5);
    delete []arr;
    return 0;
}