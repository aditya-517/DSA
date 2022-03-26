#include<bits/stdc++.h>
using namespace std;

class Human{
    public:
    int height;
    int weight;
    int age;

    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

// Child class
class Male: public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleeping";
    }
};

int main()
{ 
    Male object1;

    // Inherited from Human class
    cout<<object1.age << endl;

    object1.sleep();
    return 0;
}