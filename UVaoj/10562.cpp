#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char M[240][240],S[240];
int o=0,k;
void search(int j,int p)
{
    for(int i=p; M[j-1][i]=='-'; i++)
    {
        if(M[j][i]&&M[j][i]!=' '&&M[j][i]!='|'&&M[j][i]!='-'&&M[j][i]!='#')
        {
            int kk=i;
            S[o++]=M[j][i];
            S[o++]='(';
            if(j+3<k&&M[j+1][kk]=='|')
            {
                int ss;
                for(ss=kk; ss>=0; ss--)
                    if(M[j+2][ss]!='-')break;
                if(M[j+2][ss]!='-')ss++;
                search(j+3,ss);
            }
            S[o++]=')';
        }
    }
}
int main()
{
    // freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++)
    {
        memset(M,0,sizeof(M));
        k=0;
        while(gets(M[k])!=NULL)
        {
            if(M[k][0]=='#')break;
            else k++;
        }
        o=0;
        S[o++]='(';
        for(int s=0; M[0][s]; s++)
        {
            if(M[0][s]!=' '&&M[0][s]!='|'&&M[0][s]!='-'&&M[0][s]!='#')
            {
                S[o++]=M[0][s];
                S[o++]='(';
                if(k>3&&M[1][s]=='|')
                {
                    int ss;
                    for(ss=s; ss>=0; ss--)if(M[2][ss]!='-')break;
                    if(M[2][ss]!='-')ss++;
                    search(3,ss);
                }
                S[o++]=')';
            }
        }
        S[o++]=')';
        S[o]='\0';
        cout<<S<<endl;
    }
    return 0;
}
