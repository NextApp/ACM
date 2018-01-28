#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[120][40],b[120][40];
int lena,lenb,d[120][120],p[120][120];
void print(int i,int j)
{
    for(int t=lenb-1; t>j; t--)
        if(d[i+1][t]&&d[i+1][t]+1==d[i][j])
        {
            for(int s=lena-1; s>i; s--)
                if(d[s][t]+1==d[i][j])
                {
                    cout<<' '<<b[t]<<"D";
                    print(s,t);
                    break;
                }
            break;
        }
}
int main()
{
    char s[120];
    int ok1=0,ok2=0;
    lena=lenb=0;
    freopen("2.txt","r",stdin);
    while(cin>>s)
    {
        if(!ok1)
        {
            if(s[0]=='#')
            {
                ok1=1;
                continue;
            }
            else
            {
                strcpy(a[lena++],s);
                continue;
            }
        }
        if(!ok2&&ok1)
        {
            if(s[0]=='#')ok2=1;
            else strcpy(b[lenb++],s);
        }
        if(ok1&&ok2)
        {
            for(int i=lena; i>=0; i--)
                for(int j=lenb; j>=0; j--)
                {
                    if(lena==i||lenb==j)d[i][j]=0;
                    else if(!strcmp(a[i],b[j]))d[i][j]=d[i+1][j+1]+1;
                    else d[i][j]=max(d[i+1][j],d[i][j+1]);
                }
            for(int j=lenb-1; j>=0; j--)
                if(d[0][j]==d[0][0]&&d[0][0])
                {
                    for(int i=lena-1; i>=0; i--)
                        if(d[i][j]==d[0][0])
                        {
                            cout<<b[j];
                            print(i,j);
                            break;
                        }
                    break;
                }
            cout<<endl;
            lena=lenb=ok1=ok2=0;
        }
    }
    return 0;
}
