#include<bits/stdc++.h>
using namespace std;

void rev(string& s, int i, int j){
    
    // base case
    if(i>j)
    return ;
    

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    i++;
    j--;

    rev(s, i, j);
}

int main()
{ 
    string s = "aditya";
    rev(s, 0, s.length()-1);
    cout<<s<<endl;
    return 0;
}