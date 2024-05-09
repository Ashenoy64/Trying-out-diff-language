#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void getMaxGold(vector<vector<int>> gold,int rows,int cols)
{
    vector<int> dp(rows,0);
    for(int i=0;i<cols;i++)
}


int main()
{
    vector<vector<int>> gold { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, n, m);
    return 0;
}