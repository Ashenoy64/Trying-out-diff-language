#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double exponent(double x,int const y)
{
    double res=1;
    int pow=y;
    if(pow<0)
    {
        res=1.0/res;
        pow=-pow;    
    }
    while(pow)
    {
        if(pow&1)
            res=res*x;
        x=x*x;
        pow=pow>>1;
    }
    return res;
}


int main()
{
    // double a=

    cout<<exponent(2.0,2);
    return 0;
}