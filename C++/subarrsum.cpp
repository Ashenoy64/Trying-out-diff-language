#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int sum(int arr[],int start,int end)
{
    int s=0;
    for(int i=start;i<end;i++)
    {
        s+=arr[i];
    }
    return s;
}

void subarrySum(int arr[],int n,int target)
{
    int start=0;
    int end=1,s;
    while(end<n)
    {
        s=sum(arr,start,end+1);
        // cout<<s<<" "<<endl;
        if(s==target)
        {
            cout<<start<<" to "<<end<<" Gives the summ\n";
            return;
        }
        else if(s>target)
        {
            if(start==end)
            {
                end++;
            }
            else
            start++;
        }
        else{
            end++;
        }
    }
    cout<<"No Sum Exist";
}


int main()
{
    int arr[]={1,3,2,5,1,1,2,3};
    subarrySum(arr,8,9);
    return 0;
}