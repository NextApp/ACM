#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int V[10][10][10][10],n,num,r;
int fa[100],re[100][100];
char M[600][200],S[100];
char man[10][20]= {"divine.","human.","evil.","night.","day."};
int cmp(const  int i,const int j)
{
    return S[i]<S[j];
}
int Judge(int i,int ok)
{
    for(int j=1; j<=num; j++)
        for(int k=1; k<=3; k++)
            if(fa[j]!=k)V[i][j][!ok][k]=1;
            else V[i][j][ok][k]=1;
}
int who(int i,int day)
{
    if(i==1||(i==2&&day==4))return 1;
    else return 0;
}
int check(int day)
{
    memset(V,-1,sizeof(V));
    for(int i=1; i<=num; i++)
        Judge(i,who(fa[i],day));
    for(int i=0; i<n; i++)
    {
        int a,b,c,d,e;
        a=M[i][0]-'A'+1;
        if(M[i][4]=='t')
        {
            if(M[i][9]=='d')e=4;
            else e=3;
            int ok1=who(fa[a],day);
            if((ok1&&day!=e)||(!ok1&&day==e))return 0;
        }
        else
        {
            int t=8,p=0;
            if(M[i][t]=='n')c=0,t=12;
            else c=1;
            char o=M[i][t];
            if(o=='d')d=1;
            else if(o=='h')d=2;
            else if(o=='e')d=3;
            else p=1;
            if(M[i][3]=='I')
            {
                b=a;
                if(p&&c)return 0;
            }
            else
            {
                b=M[i][3]-'A'+1;
                if(p)
                {
                    int k1=who(fa[a],day);
                    int k2=who(fa[b],day);
                    if(k1&&c&&k2)return 0;
                    if(k1&&!c&&!k2)return 0;
                    if(!k1&&c&&!k2)return 0;
                    if(!k1&&!c&&k2)return 0;
                }
            }
            if(!p&&V[a][b][c][d]!=1)return 0;
        }
    }
    return day;
}
void dfs(int cur)
{
    if(cur==num+1)
    {
        int ok=check(3)+check(4);
        if(ok)
        {
            fa[num+1]=ok;
            memcpy(re[r++],fa,sizeof(fa));
        }
    }
    else for(int i=1; i<=3; i++)
        {
            fa[cur]=i;
            dfs(cur+1);
        }
}
int main()
{
   //freopen("592.in","r",stdin);
    int id=1;
    while(cin>>n&&n)
    {
        char m[200];
        num=r=0;
        getchar();
        memset(m,0,sizeof(m));
        for(int i=0; i<n; i++)
        {
            gets(M[i]);
            char c=M[i][0],d=M[i][3];
            if(!m[c]&&c>='A'&&c<='E')
            {
                m[c]=1;
                S[num++]=c;
            }
            if(!m[d]&&d>='A'&&d<='E')
            {
                m[d]=1;
                S[num++]=d;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<num; j++)
                if(M[i][0]==S[j]){M[i][0]='A'+j;break;}
            for(int j=0; j<num; j++)
                if(M[i][3]==S[j]){M[i][3]='A'+j;break;}
        }
        dfs(1);
        printf("Conversation #%d\n",id++);
        int w[100];
        for(int i=0; i<num; i++)w[i]=i;
        sort(w,w+num,cmp);
        if(r)
        {
            int c[100],OK=re[0][num+1],mm=0;
            memset(c,0,sizeof(c));
            for(int j=1; j<=num; j++)
            {
                int ok=1;
                for(int i=1; i<r&&ok; i++)
                    if(re[i][j]!=re[0][j])ok=0;
                if(ok)c[j]=re[0][j];
            }
            for(int i=0; i<num; i++)
                if(c[w[i]+1])
                {
                    printf("%d is %s\n",S[w[i]],man[c[w[i]+1]-1]);
                    mm=1;
                }
            for(int i=1; i<r&&OK; i++)
                if(re[i][num+1]!=OK)OK=0;
            if(OK&&OK<7)
            {
                mm=1;
                printf("It is %s\n",man[OK]);
            }
            if(!mm)printf("No facts are deducible.\n");
        }
        else printf("This is impossible.\n");
        printf("\n");
    }
    return 0;
}
