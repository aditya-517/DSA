/*

Multiple parent classes
A   B
 \ /
  C

*/
#include<bits/stdc++.h>
using namespace std;

class Animal{
    public: 
    int age;

    void bark(){
        cout<< "Barking"<<endl;
    }
};

class Human{
    public:
    int name;
    int height;

    public: 
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

// Multiple Inheritance
class Hybrid: public Animal, public Human{
     
};

int main()
{ 
    Hybrid obj;
    obj.speak();
    obj.bark();
    return 0;
}