#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int countBits(int y)
{
    int count=0;
    while(y)
    {
        ++count;
        y>>=1;
    }
    return count;
}


int divide(int x,int y)
{
    int sign=x>0?0:1;

    int nCycles=countBits(y);
    int forward=countBits(x);
    int cycles=0;
    int diff=(~y)+1;
    int add=y;
    int A=0;
    int quotient=0;
    while(cycles<nCycles)
    {
        x=x<<1;
        cycles++;
    }
}


int main()
{
    return 0;
}