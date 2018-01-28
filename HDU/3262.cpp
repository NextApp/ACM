#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int M[100][100],Vis[100][100];
struct T
{
    int time;
    int num;
    int ix,iy,oo;
    int n;
} A[100];
int cmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->time-b->time)return a->time-b->time;
}
int cmpp(const void *_a,const void*_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->n - b->n)return a->n - b->n;
}
int main()
{
   //freopen("1.txt","r",stdin);
    int m,n,k;
    while(cin>>n>>m>>k)
    {
        if(!m&&!n&&!k)break;
        else
        {
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    cin>>M[i][j];
            memset(Vis,0,sizeof(Vis));
            char MM[100];
            gets(MM);
            for(int i=0; i<k; i++)
            {
                char a,b,c,d;
                a=getchar();
                b=getchar();
                getchar();
                c=getchar();
                d=getchar();
                A[i].time=((a-'0')*10+b-'0')*60+(c-'0')*10+d-'0';
                cin>>A[i].num;
                gets(MM);
                A[i].n=i;
            }
            qsort(A,k,sizeof(T),cmp);
            for(int i=0; i<k; i++)
            {
                int sum=-10000000,ix,iy,OK=0;
                for(int j=0; j<n; j++)
                {
                    for(int s=0; s+A[i].num<=m; s++)
                    {
                        if(Vis[j][s])continue;
                        int ok=0;
                        for(int t=0; t<A[i].num; t++)
                            if(Vis[j][s+t])
                            {
                                ok=1;
                                break;
                            }
                        if(sum<M[j][s]&&!ok)
                        {
                            ix=j;
                            iy=s;
                            OK=1;
                            sum=M[ix][iy];
                        }
                    }
                }
                if(OK)
                {
                    for(int kk=0; kk<A[i].num; kk++)
                        Vis[ix][iy+kk]=1;
                    A[i].ix=ix,A[i].iy=iy;
                    A[i].oo=1;
                }
                else
                {
                    int dd=-100000000,okk=0;
                    for(int j=0; j<n; j++)
                    {
                        for(int jj=0; jj<m; jj++)
                            if(M[j][jj]>=dd&&!Vis[j][jj])
                            {
                                dd=M[j][jj];
                                ix=j,iy=jj;
                                okk=1;
                            }
                    }
                    if(okk)
                    {
                        Vis[ix][iy]=1;
                        A[i].ix=ix;A[i].iy=iy;
                        A[i].oo=1;
                    }
                    else
                        A[i].oo=0;
                }
            }
            qsort(A,k,sizeof(T),cmpp);
            for(int i=0;i<k;i++)
            {
                if(A[i].oo)cout<<A[i].ix+1<<' '<<A[i].iy+1<<endl;
                else cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}
