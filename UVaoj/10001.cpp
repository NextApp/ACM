#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l[]= {0,0,0,0,1,1,1,1};
int b[]= {0,0,1,1,0,0,1,1};
int r[]= {0,1,0,1,0,1,0,1};
int m,n,M[100],s[100],OK,e;
char a[100];
void dfs(int cur)
{
    if(cur==n) {
        if(s[n]==s[0]&&e==s[n-1])OK=1;
    } else for(int i=0; i<8; i++) {
            if(M[i]==a[cur]&&l[i]==s[cur-1]&&b[i]==s[cur]) {
                s[cur+1]=r[i];
                dfs(cur+1);
            }
        }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(scanf("%d%d%s",&m,&n,a)==3) {
        for(int i=0; i<8; i++) {
            M[i]=m%2;
            m/=2;
        }
        OK=0;
        for(int i=0; i<n; i++)a[i]-='0';
        for(int i=0; i<8; i++) {
            if(M[i]==a[0]) {
                s[0]=b[i];
                s[1]=r[i];
                e=l[i];
                dfs(1);
            }
        }
        if(OK)printf("REACHABLE\n");
        else printf("GARDEN OF EDEN\n");
    }
    return 0;
}
