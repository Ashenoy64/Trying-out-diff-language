#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x=10;
    int y=1;
    int l=2,r=3;
    int bit_map = ((1<<(r-l+1))-1)<<l;
    int bit_copied = x & bit_map;
    cout<<(y|bit_copied)<<endl;
    return 0;
}