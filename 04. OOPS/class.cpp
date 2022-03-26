#include<bits/stdc++.h>
using namespace std;

class Hero
    {   
        private:
        int health;

        public:
        char level;
        static int timeToComplete;
        
        // Static function
        // It can access static members only
        static int random()
        {
            return timeToComplete;
        }

        // Constructor
        Hero(){
            cout<<"Constructor Called"<<endl;
        }

        int getHealth(){
            return health;
        }

        void setHealth(int h){
            health = h;
        }

        // Destructor
        // It is called automatically for static objects, and it should be called manually for dynamic ones
        ~Hero(){
            cout<< "Destructor called "<<endl;
        }
    };

// Initialising static variable
int Hero::timeToComplete = 5;

int main()
{ 
    
    cout<< Hero::timeToComplete << endl;
    cout<< Hero::random() << endl;

    // // Creating object

    // // Static allocation
    // Hero h1;

    // // Dynamically 
    // Hero *h2 = new Hero;

    // cout<< (*h2).level;
    // cout<< h2->level;

    // cout<<"Size of Object : " << sizeof(h1) << endl;          // Size of class
    // cout<<"Size of Empty Object : " << sizeof(h1) << endl;   // 1 byte

    // h1.level = 'A';
    // cout<< h1.level<<endl;

    // h1.setHealth(100);      // Setting Health
    // cout<<"Health is " << h1.getHealth();

    // // Calling destructor manually for dynamic objects
    // delete h2;
    return 0;
}