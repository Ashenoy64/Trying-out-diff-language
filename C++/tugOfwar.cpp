#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int helper(vector<int> v, vector<int> &ans,int cur_sum,int left_sum,int index)
{
    if(index<0)
    return INT_MAX;

    if(ans.size()>v.size()/2)
    return INT_MAX;

    if(ans.size()==v.size())
        return abs(left_sum-cur_sum);
    
    int notTake = helper(v,ans,cur_sum,left_sum,index-1);
    cur_sum+=v[index];
    ans.push_back(v[index]);
    left_sum -=v[index];
    
    int take = helper(v,ans,cur_sum,left_sum,index-1);

    if(take<=notTake)
    return take;
    
    ans.pop_back();
    return notTake;
}


vector<int> solve(vector<int> v)
{
    vector<int> ans;
    int sum = accumulate(v.begin(),v.end(),0);


    cout<<helper(v,ans,0,sum,v.size()-1)<<endl;


    return ans;
}


int main()
{
    vector<int> v={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    vector<int> ans = solve(v);

    for(auto a:ans)
    cout<<a<<", ";
    return 0;
}