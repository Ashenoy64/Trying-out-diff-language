#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void make_alternate(vector<int> v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        if(i%2==0 and v[i]>v[i+1])
        {
            int temp=v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
        }
        else if(i%2==1 and v[i]<v[i+1]){
            int temp=v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
        }
    }
    for(auto a:v)
    cout<<a<<" ";
}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];

    make_alternate(v);
    return 0;
}