#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

int dirX[4]={0,-1,0,-1};
int dirY[4]={-1,0,1,0};


int max_len=0;

void traverser(vector<vector<int>> &mat, int i,int j, int x, int y,int len)
{
    if(i==x and j == y)
    {
        if(len>max_len)
        {
            max_len=len;
            cout<<"Len "<<len<<endl;
        }

        return;
    }



    for(int k=0;k<4;k++)
    {
        int X = i + dirX[k];
        int Y = j + dirY[k];
        if(X>=0 and Y>=0 and X<R and Y<C and mat[X][Y]==1)
        {
            mat[X][Y]=0;
            traverser(mat,X,Y,x,y,len+1);
            mat[X][Y]=1;
        }
    }
}


void findLongestPath(vector<vector<int>> &mat, int i, int j, int x, int y)
{
    mat[0][0]=1;
    traverser(mat,0,0,x,y,0);
    cout<<"Max_length = "<<max_len;
}

int main()
{
    // input matrix with hurdles shown with number 0
    vector<vector<int>> mat = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
 
    return 0;
}