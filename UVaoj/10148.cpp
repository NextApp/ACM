#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#define Nm 10000
using namespace std;
int M[21000];
struct T
{
    int a,b;
} m[1200];
typedef struct
{
    int mk,k;
} Node;
struct cmp
{
    bool operator()(const Node &t1,const Node &t2)
    {
        if(t1.mk!=t2.mk)return t1.mk>t2.mk;
        else return t1.k>t2.k;
    }
};
int ccmp(const void *_a,const void *_b)
{
    T*a=(T*)_a;
    T*b=(T*)_b;
    if(a->b - b->b)return a->b - b->b;
    else return b->a - b->a;
}
int S[20100];
int main()
{
   // freopen("1.txt","r",stdin);
    int num,N,K;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cin>>K>>N;
        int a,b;
        memset(M,0,sizeof(M));
        for(int j=0; j<N; j++)
        {
            cin>>a>>b;
            if(a>b)m[j].a=b+Nm,m[j].b=a+Nm;
            else m[j].a=a+Nm,m[j].b=b+Nm;
            if(m[j].b-m[j].a<K)
            {
                for(int k=m[j].a; k<=m[j].b; k++)
                    M[k]=-1;
                j--;
                N--;
            }
            else
            {
                for(int k=m[j].a; k<=m[j].b; k++)
                    if(M[k]!=-1)M[k]++;
            }
        }
        priority_queue<Node,vector<Node>,cmp>D;
        qsort(m,N,sizeof(T),ccmp);
        for(int j=0; j<N; j++)
        {
            int OKK=0;
            for(int t=j-1; t>=0; t--)
            {
                if(m[j].a<=m[t].a)
                {
                    OKK=1;
                    for(int k=m[j].a; k<=m[j].b; k++)
                        if(M[k]!=-1)M[k]--;
                    break;
                }
            }
            if(OKK)continue;
            int size=K;
            for(int k=m[j].a; k<=m[j].b; k++)
            {
                if(!size)break;
                else
                {
                    Node u;
                    u.mk=M[k];
                    u.k=k;
                    int ok=0;
                    if(M[k]==-1)
                    {
                        size--;
                        ok=1;
                    }
                    if(!ok)D.push(u);
                    while(D.size()>size)D.pop();
                }
            }
            while(!D.empty())
            {
                Node u=D.top();
                M[u.k]=-1;
                D.pop();
            }
            for(int k=m[j].a; k<=m[j].b; k++)
                if(M[k]!=-1)M[k]--;
        }
        if(i)cout<<endl;
        int k=0;
        for(int j=0; j<20001; j++)
            if(M[j]==-1)S[k++]=j-Nm;
        cout<<k<<endl;
        for(int j=0;j<k;j++)
        cout<<S[j]<<endl;
    }
    return 0;
}
