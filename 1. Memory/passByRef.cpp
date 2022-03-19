#include<bits/stdc++.h>
using namespace std;

// Pass by value
void update(int n){
    n++;
}

// Pass by reference
void update2(int& n){
    n++;
}

int main()
{ 
    int n = 5; 
    cout<< "Before " << n << endl;
    // update(n);
    update2(n);
    cout<<"After " << n << endl;
    return 0;
}