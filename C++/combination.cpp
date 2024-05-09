#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void vectorPrint(vector<int> ans)
{
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
}


void recursion(vector<int> v,vector<int> ans,int i,int r,int size)
{
    if(ans.size()>=r)
    {
        vectorPrint(ans);
        return;
    }

    if(i>=size)
        return;

    for(int k=i;k<v.size();k++)
    {
        ans.push_back(v[k]);
        recursion(v,ans,k+1,r,size);
        ans.pop_back();
    }
}



int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int r = 3;
    vector<int> ans;
    recursion(arr,ans,0,r,arr.size());
}