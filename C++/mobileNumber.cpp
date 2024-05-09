#include<iostream>
#include<bits/stdc++.h>

using namespace std;




string solve(string s)
{
    string ans="";
    string str[]= { "2",   "22",  "222", "3",   "33",   "333", "4","44",  "444", "5",   "55",  "555",  "6",   "66","666", "7",   "77",  "777", "7777", "8",   "88","888", "9",   "99",  "999", "9999" };
    for(int i =0 ;i<s.size();i++)
    {
        char x=s[i];
        if(x>='A' and x<='Z')
        {
            cout<<str['A'-x]<<endl;
        }
        else if(x>='a' and x<='z')
        {
            cout<<"Lower"<<x<<endl;
            ans+=str['a'-x];
        }
    }

    return ans;
}


int main()
{
    string text="GEEKSFORGEEKS";
    cout<<solve(text)<<endl;
    return 0;
}