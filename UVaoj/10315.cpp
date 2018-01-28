#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char M[20][3];
int tol[140],vis[140];
int cmp(const void *_a,const void *_b)
{
    char *a=(char*)_a;
    char *b=(char*)_b;
    return tol[a[0]]-tol[b[0]];
}
int A[12];
char puke[10][6];
struct T
{
    int v;
    int a[10];
} black,white;
void init()
{
    for(int i=2; i<=9; i++)
        tol['0'+i]=i;
    tol['T']=10;
    tol['J']=11;
    tol['Q']=12;
    tol['K']=13;
    tol['A']=14;
}
int calculate(int c)
{
    int v[200];
    memset(vis,0,sizeof(vis));
    memset(v,0,sizeof(v));
    for(int i=0; i<5; i++)
        vis[puke[i][0]]++;
    int ok=0;
    for(int i=0; i<5; i++)
    {
        char d=puke[i][0];
        if(!v[d]&&vis[d]==c)
        {
            v[d]=1;
            ok++;
        }
    }
    return ok;
}
int compare(T &a,T &b)
{
    int ok=0;
    if(a.v>b.v)ok=1;
    else if(a.v==b.v)
    {
        for(int i=0; i<5; i++)
            if(a.a[i]>b.a[i])
            {
                ok=1;
                break;
            }
            else if(a.a[i]<b.a[i])
            {
                ok=-1;
                break;
            }
    }
    else ok=-1;
    return ok;
}
void Highcard(T&a)
{
    a.v=1;
    int t=0;
    for(int i=4; i>=0; i--)
        a.a[t++]=tol[puke[i][0]];
}
int Pair(T&a)
{
    if(calculate(2)==1)
    {
        a.v=2;
        int t=0;
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]==2)
                a.a[t++]=tol[puke[i][0]];
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]!=2)
                a.a[t++]=tol[puke[i][0]];
        return 1;
    }
    else return 0;
}
int TwoPairs(T&a)
{
    if(calculate(2)==2)
    {
        a.v=3;
        int t=0;
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]==2)
                a.a[t++]=tol[puke[i][0]];
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]!=2)
                a.a[t++]=tol[puke[i][0]];
        return 1;
    }
    else return 0;
}
int Threeofkind(T&a)
{
    if(calculate(3))
    {
        a.v=4;
        int t=0;
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]==3)
                a.a[t++]=tol[puke[i][0]];
        /*for(int i=4; i>=0; i--)
              if(vis[puke[i][0]]!=3)
                  a.a[t++]=tol[puke[i][0]];*/
        return 1;
    }
    else return 0;
}
int Straight(T &a)
{
    for(int i=0; i<3; i++)
        if(tol[puke[i][0]]!=tol[puke[i+1][0]]-1)return 0;
    if(puke[4][0]=='A')
    {
        if(puke[3][0]!='5'&&puke[3][0]!='K')return 0;
    }
    else if(tol[puke[3][0]]!=tol[puke[4][0]]-1)return 0;
    a.v=5;
    for(int i=0; i<5; i++)
        a.a[i]=tol[puke[4][0]];
    return 1;
}
int Flush(T&a)
{
    for(int i=0; i<4; i++)
        if(puke[i][1]!=puke[i+1][1])return 0;
    a.v=6;
    int t=0;
    for(int i=4; i>=0; i--)
        a.a[t++]=tol[puke[i][0]];
    return 1;
}
int Full_H(T&a)
{
    if(calculate(3)&&calculate(2))
    {
        a.v=7;
        int t=0;
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]==3)
                a.a[t++]=tol[puke[i][0]];
        /* for(int i=4; i>=0; i--)
             if(vis[puke[i][0]]==2)
                 a.a[t++]=tol[puke[i][0]];*/
        return 1;
    }
    return 0;
}
int Fourofkind(T&a)
{
    if(calculate(4))
    {
        a.v=8;
        int t=0;
        for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]==4)
                a.a[t++]=tol[puke[i][0]];
        /*for(int i=4; i>=0; i--)
            if(vis[puke[i][0]]!=4)
                a.a[t++]=tol[puke[i][0]];*/
        return 1;
    }
    return 0;
}
int Straight_flush(T &a)
{
    if(Flush(a)&&Straight(a))
    {
        a.v=9;
        return 1;
    }
    return 0;
}
void check(T &a)
{
    if(Straight_flush(a));
    else if(Fourofkind(a));
    else if(Full_H(a));
    else if(Flush(a));
    else if(Straight(a));
    else if(Threeofkind(a));
    else if(TwoPairs(a));
    else if(Pair(a));
    else Highcard(a);
}
int main()
{
    freopen("1.txt","r",stdin);
    init();
    while(~scanf("%s",puke[0]))
    {
        for(int i=1; i<5; i++)
            scanf("%s",puke[i]);
        qsort(puke,5,sizeof(puke[0]),cmp);
        check(black);
        for(int i=0; i<5; i++)
            scanf("%s",puke[i]);
        qsort(puke,5,sizeof(puke[0]),cmp);
        check(white);
        int o=compare(black,white);
        if(o==1)printf("Black wins.\n");
        else if(o)printf("White wins.\n");
        else printf("Tie.\n");
    }
    return 0;
}
