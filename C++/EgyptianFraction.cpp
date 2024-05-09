#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void egyptianFraction(int n, int d)
{
    if(d==0 || d == 0)
    {
        return ;
    }

    
    if(n%d==0)
    {
        cout<<n/d;
        return;
    }
    if(d%n==0)
    {
        cout<<1<<"/"<<d/n;
        return;
    }
    if(n>d)
    {
        cout<<n/d<<"+";
        return egyptianFraction(n%d,d);
    }
    int ans = ceil((float)d/n);

    cout<<" "<<1<<'/'<<ans<<" +";

    return egyptianFraction(n*ans - d,d*ans);

}

int main()
{
    egyptianFraction(23,2);
    return 0;
}