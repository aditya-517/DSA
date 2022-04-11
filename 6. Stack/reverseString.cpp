#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    stack<char> s;
    string str = "abcde";

    for(char c: str)
        s.push(c);
    
    string ans = "";
    while(s.empty() == false){
        char c = s.top();
        s.pop();
        ans += c;
    }
    cout<<ans<<endl;
    return 0;
}