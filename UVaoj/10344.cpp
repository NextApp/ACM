#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[6],OK,k=0,t;
int M[200][6];
int next()
{
    int p[6];
    for(int i=0; i<5; i++)p[i]=i;
    sort(p,p+5);
    do
    {
        for(int i=0; i<5; i++)M[k][i]=p[i];
        k++;
    }
    while(next_permutation(p,p+5));

}
int dfs(int cur,int v)
{
    if(cur==4&&v==23)OK=1;
    else if(!OK&&cur<4)
    {
        dfs(cur+1,v-a[M[t][cur+1]]);
        dfs(cur+1,v+a[M[t][cur+1]]);
        dfs(cur+1,v*a[M[t][cur+1]]);
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    next();
    while(cin>>a[0])
    {
        for(int i=1; i<5; i++)cin>>a[i];
        int ok=0;
        for(int j=0; j<5; j++)if(a[j])
            {
                ok=1;
                break;
            }
        if(!ok)break;
        OK=0;
        for(t=0; t<k; t++)
            dfs(0,a[M[t][0]]);
        if(OK)cout<<"possible"<<endl;
        else cout<<"impossible"<<endl;
    }
}
