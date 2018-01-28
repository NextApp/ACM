#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int M[100][100],C[10],m;
int search(int cur,int v)
{
    int i,j;
    if(cur==8)
    {
        m=m>v?m:v;
    }
    else
    {
        for(i=0; i<8; i++)
        {
            int ok=1;
            C[cur]=i;
            for(int j=0; j<cur; j++)
                if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
                {
                    ok=0;
                    break;
                }
            if(ok)
                search(cur+1,v+M[cur][C[cur]]);
        }
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n=1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<8;j++)
        for(int k=0;k<8;k++)
        cin>>M[j][k];
        m=0;
        search(0,0);
        printf("%5d\n",m);
    }
    return 0;
}
