/*

Polymorphism = Many + Forms

Types : 
1. Compile Time Polymorphism (Static Polymorphism)

  - Function Overloading: 
      Functions with same name but some difference like in arguments.
      Functions only with difference in return type cannot be overloaded.


  - Operator Overloading
      Making the operator perform another function.
  
      Syntax: 
  
      <return type> operator<symbol> (<arguments>)
      { 

      } 


2. Run Time Polymorphism  (Dynammic Polymorphism)

    - Method Overriding
        Can implement through inheritance only.
        
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public: 

    // Function Overloading
    void sayHello(){
        cout<<"Hello"<<endl;
    }

    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
};

class B{
    public: 
    int a, b;

    public: 
    int add(){
        return a+b;
    }

    // Operator Overloading
    void operator+ (B &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"Output : "<< value2 - value1 <<endl;
    }

    void operator() (){
        cout<< "I am Bracket "<<this->a<<endl;
    }
};

// Method Overriding
class Animal{
    public: 
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};

int main()
{ 
    Dog obj;
    obj.speak();        // Barking

    // B obj1, obj2;
    // obj1.a = 4;
    // obj2.a = 7;

    // obj1 + obj2;        // Output : 3

    // obj1();             // I am Bracket 4

    // A obj;
    // obj.sayHello();
    return 0;
}