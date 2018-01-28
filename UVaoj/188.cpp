#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int hash(char a[])
{
    int len=strlen(a);
    int s=0;
    for(int i=0; i<len; i++)
        s+=(a[i]-'a'+1)*pow(32,len-i-1);
    return s;
}
int confict(int m,int n,int C)
{
    int a=(C/m+1)*m;
    int b=(C/n+1)*n;
    if(a>b)return b;
    else return a;
}
char word[15][6],a[1000];;
int main()
{
    //freopen("1.txt","r",stdin);
    while(gets(a)!=NULL)
    {
        int num=0,k=0,vis[15],OK=0;
        int s[15],C;
        for(int i=0; a[i]; i++)
            if(OK&&a[i]==' '&&a[i+1]<='z'&&a[i+1]>='a')
            {
                word[num][k]='\0';
                num++;
                k=0;
            }
            else if(a[i]!=' '){word[num][k++]=a[i];OK=1;}
        word[num][k]='\0';
        num++;
        for(int i=0; i<num; i++)
            s[i]=hash(word[i]);
        sort(s,s+num);
        C=s[num-2];
        while(1)
        {
            int ok=1;
            memset(vis,-1,sizeof(vis));
            for(int j=0; j<num; j++)
            {
                int t=(C/s[j])%num;
                if(vis[t]==-1)vis[t]=j;
                else
                {
                    C=confict(s[vis[t]],s[j],C);
                    ok=0;
                    break;
                }
            }
            if(ok)break;
        }
        cout<<a<<endl;
        cout<<C<<endl<<endl;
    }
    return 0;
}
