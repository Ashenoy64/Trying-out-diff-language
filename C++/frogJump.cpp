#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool frogJump(vector<int> v)
{
    int jump=v[0];
    for(int i=1;i<v.size() and jump>=i;i++)
    {
        jump=max(jump,i+v[i]);
    }
    if(jump>=v.size())
    return true;
    return false;
}


int main()
{
    vector<int> v={2,4,0,1,3};
    cout<<frogJump(v)<<endl;
    return 0;
}