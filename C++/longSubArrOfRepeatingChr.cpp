#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int calculateLength(vector<int> arr)
{
    int maxlen=1,len=1,chr=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(chr==arr[i])
        len++;
        else{
            if(maxlen<len)
            maxlen=len;
            len=1;
            chr=arr[i];
        }
            
    }
    return maxlen;
}


int main()
{
    vector<int> v={1,1,2,2,2,3};

    cout<<"length = "<<calculateLength(v)<<endl;
    return 0;
}