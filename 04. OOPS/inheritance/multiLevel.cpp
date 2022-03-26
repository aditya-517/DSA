/*

Multiple Levels

  A 
  |  
  B
  |
  C  
  
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

class B: public A{
    public:
    int name;
    

    public: 
    void Bfun(){
        cout<<"B Class Func"<<endl;
    }
};

// Multi Level Inheritance
class C: public B{
    
};

int main()
{ 
    C obj;
    obj.AFun();
    obj.Bfun();
    return 0;
}