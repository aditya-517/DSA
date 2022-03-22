#include<bits/stdc++.h>
using namespace std;

void solve(string s, int index, vector<string> &ans){

    // base case
    if(index >= s.length()){
        ans.push_back(s);
        return;
    }

    for(int i=index; i<s.length(); i++){
        swap(s[i], s[index]);
        solve(s, index+1, ans);
        swap(s[i], s[index]);       // backtracking
    }

}

int main()
{ 
    string s = "abcd";
    vector<string> ans; 
    string output;
    int index = 0;

    solve(s, index,ans);


    for(string str: ans)
    cout<<str<<" ";
    return 0;
}