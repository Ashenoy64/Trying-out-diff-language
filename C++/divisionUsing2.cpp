#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int a,int b)
{

    int diff=0;
    while(a)
    {
        a>>=1;
        b<<=1;
        if(a&1==1)
        {
            diff+=a;
        }
        
    }
    cout<<b+diff<<endl;
}

int main()
{
    solve(2,1);
    return 0;
}