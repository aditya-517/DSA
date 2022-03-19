#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int arr[5] = {50,60,70};

    // arr and &arr points to the first location of arr.
    cout<< arr << endl;
    cout<< &arr << endl;
    cout<< &arr[0] <<endl;

    cout<< (*arr) <<endl;

    // ****** IMP ******
    int i = 2;
    cout << (*(arr + i)) << endl;
    cout<< (i[arr]) <<endl;
    cout << (*(i + arr)) << endl;


    int *ptr = &arr[0];
    cout<< sizeof(ptr) <<endl;
    cout<< sizeof(*ptr) <<endl;
    cout<< sizeof(&arr) <<endl;

    return 0;
}