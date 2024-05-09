#include<iostream>
#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> result;

bool findSubsetSum(vector<int> v,int sum,vector<int> &s,int curSum,unordered_map<int,bool>&mp)
{
    if(curSum>sum)
        return false;

    if(curSum==sum)
    {
        result.push_back(s);
        return true;
    }
    for(auto x: v)
    {
        if(mp[x]==false)
        {
            mp[x]=true;
            s.push_back(x);
            bool res=findSubsetSum(v,sum,s,curSum+x,mp);
            s.pop_back();
            mp[x]=false;
            if(res==true and s.size()!=0)
                return true;
        }
    }
    return false;

}


int main()
{
    vector<int> v={1,2,3,4,5};

    // vector<int> result;

    int sum=11;
    vector<int> subset;
    unordered_map<int,bool> mp;
    findSubsetSum(v,sum,subset,0,mp);

    for(auto x:result)
    {
        for(auto i:x)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}