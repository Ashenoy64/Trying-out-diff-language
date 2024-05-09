#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int power_expo;
    cin>>power_expo;

    int num;
    cin>>num;

    cout<<(num&(1<<power_expo)-1)<<" "<<num%(1<<power_expo)<<endl;
    return 0;
}

// 4->0 (checks power of 2 if 0)
