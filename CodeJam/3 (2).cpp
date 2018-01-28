#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
#define N 7000001
#define INF 1313
using namespace std;
int vis[2000200],V[N+1000];
struct T
{
    int a,b;
    T*next;
} M[N+1000];
T*newnode()
{
    T*u=(T*)malloc(sizeof(T));
    u->next=NULL;
    return u;
}
int hash(int a,int b)
{
    long long x=a,y=b;
    return (x*INF*y)%N;
}
int insert(int i,int j)
{
    int h=hash(i,j);
    T*u=newnode();
    u->a=i;
    u->b=j;
    if(!V[h])
    {
        M[h].next=u;
        V[h]=1;
    }
    else
    {
        T*m=M[h].next;
        while(m->next!=NULL)
        {
            m=m->next;
        }
        m->next=u;
    }
}
int judge(int i,int j)
{
    int h=hash(i,j);
    if(V[h])
    {
        T*u=M[h].next;
        while(u!=NULL)
        {
            if(u->a==i&&u->b==j)return 1;
            u=u->next;
        }
    }
    return 0;
}
int main()
{
    int n;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int A,B,t,sum=0;
        cin>>A>>B;
        cout<<A<<' '<<B<<endl;
        memset(vis,0,sizeof(vis));
        memset(V,0,sizeof(V));
        for(int j=A; j<=B; j++)
        {
            int s=(int)log10(j)+1;
            for(int k=1; k<s; k++)
            {
                int t=pow(10,k);
                int a=(j%t)*pow(10,s-k)+j/t;
                if(a>j&&a<=B&&!judge(j,a))
                {
                    sum++;
                    insert(j,a);
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<sum<<endl;
    }
    return 0;
}
