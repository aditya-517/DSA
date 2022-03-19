#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int a = 5;
    int *p = &a;
    int **p2 = &p;

    cout<< (*p)++ <<endl;
    cout<< (*p) <<endl;
    cout<< sizeof(*p)<<" "<<sizeof(p) <<endl;
    cout<< (*p2)<<" "<<(**p2) <<endl;


    return 0;
}