#include<iostream>
#include<cstdio>
#include<cstring>
#define N 32000
using namespace std;
int q[6502000],m,s[108],ok,n;
int  M[6502000],D[6502000];
char F[6502000],S[108];
int bfs()
{
    int rear=0,front=0;
    q[rear++]=(s[0]+N)*100;
    while(front<rear)
    {
        int u=q[front++];
        int a=u/100-N,i=u%100+1,l;
        if(i<n)
        {
            if(a*s[i]<N&&a*s[i]>-N)
            {
                l=(a*s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='*';
                    q[rear++]=l;
                }
            }
            if(s[i]&&!(a%s[i]))
            {
               l=(a/s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='/';
                    q[rear++]=l;
                }
            }
            if(a+s[i]<N)
            {
               l=(a+s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='+';
                    q[rear++]=l;
                }
            }
            if(a-s[i]>-N)
            {
                l=(a-s[i]+N)*100+i;
                if(!M[l])
                {
                    M[l]=1;
                    D[l]=u;
                    F[l]='-';
                    q[rear++]=l;
                }
            }
        }
        else
        {
            if(a==m)
            {

                int o=1;
                int c=D[u];
                S[0]=F[u];
                while(o<n-1)
                {
                    S[o++]=F[c];
                    c=D[c];
                }
                    cout<<s[0];
                for(int i=1; i<n; i++)
                    cout<<S[n-i-1]<<s[i];
                cout<<'='<<m<<endl;
                ok=1;
                return 0;
            }
        }
    }
}
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>s[i];
        cin>>m;
        ok=0;
        memset(M,0,sizeof(M));
        bfs();
        if(!ok)
        {
            cout<<"NO EXPRESSION"<<endl;
        }
    }
    return 0;
}
