#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int smallestNonConstructible(vector<int> v)
{

    // Numbers that cannot be created using the set of numbers
    sort(v.begin(),v.end());

    int smallest=0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=smallest+1)
            smallest=smallest+v[i];
        else
            return smallest+1;
    }
    return smallest;
}


int main()
{
    int n;
    cin>>n;

    vector<int> v(n,0);

    for(int i=0;i<n;i++)
    cin>>v[i];

    cout<<"Smallest Non constructible is "<<smallestNonConstructible(v);
    return 0;
}