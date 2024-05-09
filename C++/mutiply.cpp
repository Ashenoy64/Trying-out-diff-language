#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned binAdd(unsigned a,unsigned b)
{

    int sum=0;
    int carry=0;
    int pos=0;
    while(a or b)
    {
        if(((a&1)^(b&1)^(carry&1)))
        sum=sum|1<<pos;
        carry=(a&1)&(1&b)&(1&carry);
        a=a>>1;
        b=b>>1;
        pos++;
        // cout<<sum<<endl;
    }
    return sum;
}


unsigned multiply(unsigned a,unsigned b)
{
    int sum=0;

    while(b)
    {
        if(b&1)
        {
            sum=sum<<1;
            // cout<<sum<<" "<<a;
            sum=binAdd(sum,a);
            // sum=sum<<1;

        }
        b=b>>1;

        a=a<<1;
        // cout<<sum<<" "<<b<<endl;
    }
    return sum;
}

int main()
{
    unsigned a,b;
    // cin>>a>>b;
    a=32;
    b=32;

    cout<<multiply(a,b)<<endl;
    return 0;
}