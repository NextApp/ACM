#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,l,kk=1;
char C[200];
int ddd(int i,int j)
{
    int ok=1,ss=(j-i+1)/2;
    for(int k=0;k<ss;k++)
        if(C[i+k]!=C[i+k+ss])ok=0;
    return ok;
}
int dfs(int cur)
{
    if(cur==n&&kk)
    {
        for(int i=0;i<cur;i++)
        cout<<C[i];
        cout<<endl;
        kk=0;
    }
    else if(kk)
    {
        for(char i='A';i<'A'+l;i++)
        {
            C[cur]=i;
            int ok=1;
            for(int k=0;k<cur;k++)
                if(ddd(k,cur))ok=0;
            if(ok)dfs(cur+1);
        }
    }
}
int main()
{
    while(cin>>n>>l)
    {
        kk=1;
        dfs(0);
    }
    return 0;
}
