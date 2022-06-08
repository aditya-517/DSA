#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    // create
    unordered_map<string, int> m;

    // insert
    pair<string, int> p = make_pair("Aditya", 3);
    m.insert(p);

    pair<string, int> p2("Jadhav", 2);
    m.insert(p2);

    m["Adi"] = 4;


    // Searching
    cout<<m["Adi"]<<endl;
    cout<<m.at("Aditya")<<endl;

    // cout<<m.at("Dhule")<<endl;  // => Error
    cout<<m["Dhule"]<<endl;     // => 0

    // Check if avail
    cout<<m.count("4848")<<endl;  // Returns 0 or 1

    // Remove Key
    m.erase("Adi");

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first << " " << it->second;
        cout<<endl;

        it++;
    }
    return 0;
}