#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
int C,N,M;
int a[1002000],vis[1002000];
bitset<10020000>p(1);
int prime()
{
    p.reset();
    p.set(1);
    p.set(0);
    for(int i=2;i<=4000;i++)
    {
        if(!p.test(i))
        for(int j=i+i;j<=10000000;j+=i)
        p.set(j);
    }
}
int Lowbit(int x)
{
    return x&(-x);
}
int Sum(int end)
{
    int s=0;
    while(end)
    {
        s+=a[end];
        end-=Lowbit(end);
    }
    return s;
}
int Update(int end,int s)
{
    while(end<=C)
    {
        a[end]+=s;
        end+=Lowbit(end);
    }
}
int main()
{
    int id=1;
    prime();
   // freopen("1.txt","r",stdin);
    while(cin>>C>>N>>M)
    {
        if(!C&&!N&&!M)return 0;
        else
        {
            cout<<"CASE #"<<id++<<":"<<endl;
            memset(vis,0,sizeof(vis));
            memset(a,0,sizeof(a));
            if(!p.test(M))
            {
                for(int i=1;i<=C;i++)
                Update(i,1);
            }
            for(int i=0;i<N;i++)
            {
                int I,x,y;
                cin>>I>>x>>y;
                if(!I)
                {
                    int e=vis[x]+M,t=vis[x]+y+M;
                    vis[x]+=y;
                    if(!p.test(e)&&p.test(t))
                        Update(x,-1);
                    else if(p.test(e)&&!p.test(t))
                        Update(x,1);
                }
                else
                    cout<<Sum(y)-Sum(x-1)<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}
