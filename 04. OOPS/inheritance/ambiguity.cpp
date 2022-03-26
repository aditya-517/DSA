/*
Ambiguity can arise if a class inherits two parents which have
same function name.
Here we use scope resolution operator ::
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public: 
    void func(){
        cout<<"Class A"<<endl;
    }
};

class B{
    public: 
    void func(){
        cout<<"Class B"<<endl;
    }
};

class C: public A, public B{

};

int main()
{ 
    C obj;
    obj.A::func();
    obj.B::func();

    return 0;
}