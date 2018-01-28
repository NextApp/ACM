#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int word_len[20];
char word[20][4000][20];
struct T
{
    char a[20];
    int n;
} st[400000];
int cmp(const void *_a,const void *_b)
{
    T *a=(T*)_a;
    T *b=(T*)_b;
    return strcmp(a->a,b->a);
}
bool vis[4000][4000],v[4000];
int q[10000],father[10000],path[10000];
int bfs(int n,int s,int e,int len)
{
    int front=0,rear=1;
    memset(v,false,sizeof(v));
    memset(father,-1,sizeof(father));
    q[front]=s;
    if(s==e)
    {
        int ok=0;
        for(int i=0; i<n; i++)
            if(s!=i&&vis[s][i])
            {
                ok=1;
                printf("%s\n",word[len][e]);
                printf("%s\n",word[len][i]);
                printf("%s\n",word[len][e]);
                return 1;
            }
            printf("%s\n",word[len][e]);
        return 1;
    }
    while(front<rear)
    {
        int u=q[front++];
        for(int i=0; i<n; i++)
            if(vis[u][i]&&!v[i])
            {
                q[rear]=i;
                father[rear++]=front-1;
                if(i==e)
                {
                    int c=rear-1,num=0;
                    while(c!=-1)
                    {
                        path[num++]=q[c];
                        c=father[c];
                    }
                    for(int j=num-1; j>=0; j--)
                        printf("%s\n",word[len][path[j]]);
                    return 1;
                }
                v[i]=true;
            }
    }
    return 0;
}
int c[100000];
int main()
{
  //  freopen("1.txt","r",stdin);
    int num=0;
    char A[20];
    memset(word_len,0,sizeof(word_len));
    while(gets(A)!=NULL)
    {
        if(A[0]=='\0')break;
        int len=strlen(A);
        strcpy(word[len][word_len[len]++],A);
    }
    char start[20],end[20];
    int sss=0;
    while(~scanf("%s%s",start,end))
    {
        int ok=1;
        int lens=strlen(start);
        int lene=strlen(end);
        if(sss)printf("\n");
        sss=1;
        if(lens!=lene)ok=0;
        else
        {
            int num=0,s=-1,e=-1;
            for(int j=0; j<word_len[lens]; j++)
            {
                if(s<0&&!strcmp(start,word[lens][j]))s=j;
                if(e<0&&!strcmp(end,word[lens][j]))e=j;
                for(int k=0; k<lens; k++)
                {
                    char a[20];
                    int t=0;
                    for(int i=0; i<lens; i++)
                        if(k!=i)a[t++]=word[lens][j][i];
                        else a[t++]='A';
                    a[t]='\0';
                    st[num].n=j;
                    strcpy(st[num++].a,a);
                }
            }
            if(s==-1||e==-1)ok=0;
            else
            {
                memset(vis,false,sizeof(vis));
                qsort(st,num,sizeof(st[0]),cmp);
                int c_num=0;
                for(int i=0; i<num-1; i++)
                {
                    int o=0;
                    while(i<num-1&&!strcmp(st[i].a,st[i+1].a))
                    {
                        o=1;
                        c[c_num++]=st[i].n;
                        i++;
                    }
                    if(o)
                    {
                        c[c_num++]=st[i].n;
                        for(int j=0; j<c_num-1; j++)
                            for(int k=j+1; k<c_num; k++)
                                vis[c[k]][c[j]]=vis[c[j]][c[k]]=true;
                        c_num=0;
                    }
                }
                ok=bfs(word_len[lens],s,e,lens);
            }
        }
        if(!ok)printf("No solution.\n");
    }
    return 0;
}
