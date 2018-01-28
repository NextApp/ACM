#include<iostream>
#include<cstdio>
#include<cstring>
#define N 34943
using namespace std;
char a[1200];
int main()
{
    while(gets(a)!=NULL)
    {
        if(a[0]=='#')break;
        else
        {
            int len=strlen(a);
            int s=0;
            for(int i=0; i<=len; i++)
                s=(a[i]+256*s)%N;
            s=(N-(s*256)%N)%N;
            int b[6],i=0;
            memset(b,0,sizeof(b));
            /*char c[6];
            sprintf(c,"%04x",(int)s);
            cout<<c<<endl;*/
            while(s/16)
            {
                b[i++]=s%16;
                s/=16;
            }
            b[i]=s;
            for(int j=3; j>=0; j--)
            {
                if(b[j]<10)cout<<b[j];
                else cout<<(char)(b[j]+'A'-10);
                if(j==2)cout<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
