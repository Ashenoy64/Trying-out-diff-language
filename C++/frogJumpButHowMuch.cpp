#include<iostream>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<int> visited(1000,0);

int frogJump(vector<int> v,int k)
{

    if(k>=v.size())
        return 1;

    if(visited[k]!=0)
        return visited[k]+1; 
    int steps=v[k];
    int pos=0;
    for(int i=steps;i!=0;i--)
    {
        pos=frogJump(v,i+k);
        if(pos){
            visited[k]=pos;
            return pos+1;

        }
    }   
    return 0;
}


int main()
{
    vector<int> v={1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9,1,3,5,8,9,2,6,7,6,8,9};
    auto start=high_resolution_clock::now();
    cout<<frogJump(v,0)-1<<endl;
    auto stop =high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout<<"Time taken : "<<duration.count() <<" microsecondds"<<endl;
    return 0;
}