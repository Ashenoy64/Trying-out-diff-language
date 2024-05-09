#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void mulBig(vector<int> a,vector<int> b)
{
    vector<int> res(a.size()+b.size(),0);
    for(int i=a.size()-1;i>=0;--i)
    {
        for(int j=b.size()-1;j>=0;--j)
        {
            res[i+j+1]+=a[i]*b[j];
            res[i+j]+=res[i+j+1]/10;
            res[i+j+1]%=10;
        }
    }
    int i=0;
    for(;i<res.size();i++)
            cout<<res[i];

    cout<<endl;

    // for(int j=res.size()-1;j>=i;j--)
    //     cout<<res[j];

    cout<<endl;
    return;

}



int main()
{
    vector<int> a={9,9,9};
    vector<int> b={9,9,9};
    mulBig(a,b);
    return 0;
}