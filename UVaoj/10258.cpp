#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;
struct T
{
    int id,problem_id,time;
    char state;
} A[12000];
struct P
{
    int wrong[12],Time[12];
    int problem,time,v,id;
} M[120];
int vis[120][12];
int cmp(const void *_a,const void *_b)
{
    P*a=(P*)_a;
    P*b=(P*)_b;
    if(a->problem-b->problem)return b->problem - a->problem;
    else if(a->time-b->time)return a->time-b->time;
    else return a->id-b->id;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    getchar();
    int ii=0;
    while(T--)
    {
        if(ii)printf("\n");
        ii=1;
        char a[100];
        int num=0;
        while(gets(a)!=NULL)
        {
            if(a[0]=='\0')break;
            else
            {
                stringstream fin(a);
                fin>>A[num].id;
                fin>>A[num].problem_id;
                fin>>A[num].time;
                fin>>A[num++].state;
            }
        }
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<num; i++)
        {
            int id=A[i].id,p=A[i].problem_id,t=A[i].time;
            M[id].v=1;
            M[id].id=id;
            if(!vis[id][p]&&A[i].state=='C')
            {
                vis[id][p]=1;
                M[id].Time[p]=t;
                M[id].time+=t;
                M[id].problem++;
            }
        }
        for(int i=0; i<num; i++)
        {
            int id=A[i].id,p=A[i].problem_id,t=A[i].time;
            if(A[i].state=='I'&&vis[id][p])
            {
                if(t<=M[id].Time[p])M[id].time+=20;
            }
        }
        qsort(M+1,100,sizeof(M[0]),cmp);
        for(int i=1; i<=100; i++)
            if(M[i].v)printf("%d %d %d\n",M[i].id,M[i].problem,M[i].time);
    }
    return 0;
}
