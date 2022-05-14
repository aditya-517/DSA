#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<"Size of Queue : " << q.size()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Back : "<<q.back()<<endl;

    q.pop();
    cout<<"Size of Queue : " << q.size()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Back : "<<q.back()<<endl;



    return 0;
}