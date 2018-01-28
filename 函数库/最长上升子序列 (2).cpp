#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,d[10050];
struct T
{
    int a,p;
} c[10050];
int binary_search(int m,int num)
{
    int a=1,b=m;
    while(a<=b)
    {
        int k=(a+b)/2,s=(k==m||c[k+1].a>num);
        if(c[k].a<num&&s)return c[k].p;
        else if(s)b=k-1;
        else a=k+1;
    }
    return -1;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        int a,t,m=1;
        for(int i=0; i<n; i++)
        {
            t=d[i]=1;
            cin>>a;
            if(!i)c[1].a=a,c[1].p=0;
            else
            {
                int k=binary_search(m,a);
                if(k>=0)t=d[i]=d[k]+1;
                if(t>m||a<c[t].a)
                {
                    c[t].a=a;
                    c[t].p=i;
                    m=max(m,t);
                }
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
