#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int update(vector<int>&v,int m)
{
    int len=1;
    int chr=v[0];
    int times=min(2,m);
    int writePointer=1;
    for(int i=1;i<v.size();i++)
    {   
        if(chr==v[i])
        len++;
        else{
            if(len==m)
            {
                writePointer-=m-times;
            }
            chr=v[i];
            len=1;
        }

        v[writePointer++]=v[i];

    }
    return writePointer;
}


int main()
{
    vector<int> v={1,1,1,2,2,2,2,4,5};
    int len=update(v,3);
    for(int i=0;i<len;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}