#include<iostream>
#include<cstdio>
#define N 1000000
using namespace std;
int M[105][105];
int main()
{
    for(int i=0; i<=100; i++)
        for(int j=0; j<100; j++)
        {
            if(!i)M[i][j]=i+1;
            else if(!j)M[i][j]=1;
            else M[i][j]=(M[i][j-1]%N+M[i-1][j]%N)%N;
        }
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m)return 0;
        else
            cout<<M[n][m-1]<<endl;
    }
    return 0;
}
