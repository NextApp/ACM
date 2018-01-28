#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char strings[35],result[36],cword;
int vis[130],word[36],cnt;
long long n,F[20],len;
long long count()
{
    long long sum=0,re;
    for(int i=0;i<cnt;i++)
    sum+=vis[word[i]];
    re=F[sum];
    for(int i=0;i<cnt;i++)
    if(vis[word[i]]>1)
    re/=F[vis[word[i]]];
    return re;
}
int dfs(int cur,long long num)
{
    if(cur==len)
    {
        return num;
    }
    long long sum=0;
    for(int i=0;i<cnt;i++)
    if(vis[word[i]])
    {
        vis[word[i]]--;
        long long s=count();
        if(sum<=num&&sum+s>=num)
        {
            result[cur]=word[i];
            return dfs(cur+1,num-sum);
        }
        else sum+=s;
        vis[word[i]]++;
    }
    return -1;
}
int main()
{
   // freopen("1.txt","r",stdin);
    F[0]=F[1]=1;
    for(int i=2;i<=18;i++)
    F[i]=F[i-1]*i;
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%lld",strings,&n);
        int ok=2;
        len=strlen(strings);
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<len;i++)
        {
            if(!vis[strings[i]])word[cnt++]=strings[i];
            vis[strings[i]]++;
        }
        cword=0;
        sort(word,word+cnt);
        for(int i=0;i<cnt;i++)
        {
            if(vis[word[i]]%2)
            {
                ok--;
                vis[word[i]]--;
                cword=word[i];
            }
        }
        if(cnt==1&&n>1)ok=0;
        if(ok>0)
        {
            len/=2;
            for(int i=0;i<cnt;i++)
                vis[word[i]]/=2;
            ok=dfs(0,n);
            if(ok>0)
            {
                int t=len;
               if(cword)result[t++]=cword;
               for(int i=0;i<len;i++)
               result[t++]=result[len-i-1];
               result[t]='\0';
            }
        }
        printf("Case %d: %s\n",id++,ok>0?result:"XXX");
    }
    return 0;
}
