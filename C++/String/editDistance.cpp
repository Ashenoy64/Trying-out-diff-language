#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int editDistance(string s1,string s2,int m,int n)
{
    if(m==0) return n;
    if(n==0) return m;
    if(s1[m-1]==s2[n-1])
        return editDistance(s1,s2,m-1,n-1);

    int i=1+min(editDistance(s1,s2,m-1,n),min(editDistance(s1,s2,m,n-1),editDistance(s1,s2,m-1,n-1))); 
    cout<<"val="<<i<<" m="<<m<<" n="<<n<<" s1="<<s1[m]<<" s2="<<s2[n]<<endl;
    return i;
}


int main()
{
    string s1="movie";
    string s2="love";
    cout<<editDistance(s1,s2,s1.size(),s2.size())<<endl;
    return 0;
}