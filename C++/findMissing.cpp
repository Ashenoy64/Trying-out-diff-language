#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solveXOR(vector<int> ans)
{
    int xor_ele=0;
    for(int i=1;i<ans[ans.size()-1]=;++i)
    xor_ele^=i;

    for(auto x:ans)
    xor_ele^=x;

    return xor_ele;
}


int solve(vector<int> ans)
{
    if(ans[0]!=1)
    return 1;
    if(ans[ans.size()-1]!=ans.size()+1)
    return ans.size()+1;
    int start =0;
    int end=ans.size()-1;

    while(start<end)
    {
        int mid = (start+end)/2;

        if(ans[start]-start!=ans[mid]-mid)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return start+1;
}


int main()
{
    vector<int> ans={2,3,4,5};
    cout<<solveXOR(ans)<<endl;
}