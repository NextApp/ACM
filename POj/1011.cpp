#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int stick[100],sizenum,size[60],sizen[60],cul;
bool cmp(int a,int b)
{
    return a>b;
}
bool vis[60];
bool search(int leave,int cur,int allsize)
{
    int ok=0;
    if(!leave)
    {
        if(allsize)leave=cul,allsize--;
        else return true;
        cur=0;
    }
    for(int i=cur; i<sizenum; i++)
        if(size[i]<=leave&&sizen[i])
        {
            sizen[i]--;
            int u=leave-size[i]-size[i]>=0?i:i+1;
            if(!search(leave-size[i],u,allsize))
            {
                sizen[i]++;
                if(leave==cul||leave==size[i])return false;
            }
            else return true;
        }
    return false;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&stick[i]);
        sort(stick,stick+n,cmp);
        sizenum=-1;
        int all=0,big=0;
        memset(vis,false,sizeof(vis));
        memset(sizen,0,sizeof(sizen));
        for(int i=0; i<n; i++)
        {
            int u=stick[i],ok=0;
            big=max(u,big);
            all+=u;
            if(!vis[u])
            {
                ok=1;
                size[++sizenum]=u;
                vis[u]=true;
            }
            sizen[sizenum]++;
        }
        sizenum++;
        for(cul=big; cul<=all; cul++)
            if(all%cul==0)
            {
                if(search(0,0,all/cul))break;
            }

        printf("%d\n",cul);
    }
    return 0;
}
