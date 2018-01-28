#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,P[25],maxx;
struct T
{
    int a,b,v;
} A[30];
int print_subet(int cur)
{
    int C[10],ok=1,t=0,L[10];
    memset(L,0,sizeof(L));
    for(int i=0; i<cur&&ok; i++)
    {
        int j=P[i];
        for(int a=A[j].a+1; ok&&a<=A[j].b; a++)
        {
            L[a]+=A[j].v;
            if(L[a]>k)ok=0;
        }
        t+=(A[j].b-A[j].a)*A[j].v;
    }
    if(ok)
    {
        if(t>maxx)maxx=t;
    }
    else return 0;
    int s=cur?P[cur-1]+1:0;
    for(int i=s; i<n; i++)
    {
        P[cur]=i;
        print_subet(cur+1);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>k>>m>>n)
    {
        if(!k&&!m&&!n)return 0;
        else
        {
            for(int i=0; i<n; i++)
                cin>>A[i].a>>A[i].b>>A[i].v;
            int L[30];
            maxx=0;
            print_subet(0);
            cout<<maxx<<endl;
        }
    }
    return 0;
}
