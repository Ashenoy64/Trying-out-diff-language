#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int popcount(int x){
    int result=0;
    while(x){
        result++;
        x=x&(x-1);
    }
    return result;
}

void approch_one(int x) //short words O(k)
{
    short result=0;
    while(x)
    {
        result^=1;
        x&=(x-1);
    }
    cout<<result<<endl;
}

vector<bool>precomputed_cache;

void approch_two(long unsigned int x) //long words O(n/L) here L=16 and n=64
{
    //this can be done by precomputing the parity of short words into the cache and and combining them into result  
    int shortwordsize=16;
    int bitmask=0xFFFF;

    cout<<(precomputed_cache[(x>>3*shortwordsize)]^
           precomputed_cache[(x>>2*shortwordsize)&bitmask]^
           precomputed_cache[(x>>shortwordsize)&bitmask]^
           precomputed_cache[x&bitmask] )<<endl;

}

void approch_three(long unsigned int x)//O(logn) n=word size
{
    x&=x>>32;
    x&=x>>16;
    x&=x>>8;
    x&=x>>4;
    x&=x>>2;
    x&=x>>16;
    x&=x>>1;
    cout<<(x&0x1)<<endl;
}


int main()
{
    int lower,upper;

    lower=10;
    // cin>>lower>>upper;

    int parity=(__builtin_popcount(lower)+__builtin_popcount(upper))%2; //O(k) time complexity k is the number of bits
    cout<<parity<<endl;



    return 0;
}