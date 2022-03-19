#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int a[3] = {1,2,3};
    char ch[6] = "abcde";
    int *p = &a[0];
    cout<<p<<endl;      // Prints address of a[0]

    char *ptr = &ch[0];
    cout<<ptr<<endl;    // Prints entire char array abcde
    return 0;
}