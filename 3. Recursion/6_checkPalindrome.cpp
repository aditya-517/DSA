#include<bits/stdc++.h>
using namespace std;

bool checkPal(string s, int i, int j){
    if(i>j)
    return true;

     if(s[i] != s[j])
     return false;

    return ((s[i] == s[j]) && checkPal(s, i+1, j-1)) ;
}

int main()
{ 
    string s = "baab";
    cout << checkPal(s, 0, s.length()-1)<<endl;
    return 0;
}