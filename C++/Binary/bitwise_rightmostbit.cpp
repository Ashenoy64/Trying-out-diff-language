#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin>>a;

    cout<<(a&~(a-1))<<endl;
    
    return 0;
    
}

//5->  1 (101)
//4-> 4(100)