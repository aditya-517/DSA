/*
A single class can have multiple child classes

        A
       /  \
      B    C
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public: 
    int age;

    void AFun(){
        cout<< "A Class function"<<endl;
    }
};

// Hierarchical Inheritance
class B: public A{

};

class C: public A{
    
};

int main()
{ 
    B obj1;
    obj1.AFun();

    C obj2;
    obj2.AFun();
    
    return 0;
}