#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=100005;
const int MAXHASHSIZE=1000003;
int head[MAXHASHSIZE],next[MAXHASHSIZE],nu[MAXHASHSIZE];
int Big,Bignum,a[MAXSIZE];
int hash(int s)
{
    return s%MAXHASHSIZE;
}
void init()
{
    memset(head,0,sizeof(head));
    memset(nu,0,sizeof(nu));
    Big=Bignum=0;
}
void change(int s)
{
    if(Bignum<nu[s]||(Bignum==nu[s]&&Big<a[s]))
    {
        Bignum=nu[s];
        Big=a[s];
    }
}
int try_to_insert(int s)
{
    int h=hash(a[s]);
    int u=head[h];
    while(u)
    {
        if(a[s]==a[u])
        {
            nu[u]++;
            change(u);
            return 0;
        }
        u=next[u];
    }
    next[s]=head[h];
    head[h]=s;
    nu[s]++;
    change(s);
    return 1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        init();
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            try_to_insert(i);
        }
        cout<<Big<<' '<<Bignum<<endl;
    }
    return 0;
}
