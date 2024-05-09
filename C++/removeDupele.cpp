#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int removeDuplicateAndShift(vector<int> &v,int m)
{
    int writePointer=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==m)
            continue;
        v[writePointer++]=v[i];
    }
    return writePointer;
}


int main()
{
    vector<int>v={1,2,3,1,7,6,4,5};
    int len=removeDuplicateAndShift(v,1);

    for(int i=0;i<len;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}