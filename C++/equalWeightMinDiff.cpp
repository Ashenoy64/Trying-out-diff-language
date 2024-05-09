#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int findSameWeight(int n)
{
    int ind=0;
    if(n%2==0)
    {
        while( (n&1<<ind) ==0) ind++;
        n=(n-1)&n;
        n=n|1<<(ind-1);
    }  
    else
    {
        while((n& 1<<ind)==1)ind++;
        n=n|1<<ind;
        n=n^(1<<(ind-1));
    }
    return n;
}

int main()
{
    int num=13;
    int nearestNum=findSameWeight(num);
    cout<<"absolute diff="<<abs(num-nearestNum)<<endl;
    return 0;
}