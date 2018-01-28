#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int change(char S[],unsigned int m)//十进制转换成二进制
{
    int i=0;
    while(m/2)
    {
        S[i++]=m%2+'0';
        m/=2;
    }
    S[i]=m+'0';
    S[i+1]='\0';
}
int main()
{
    //freopen("1.txt","r",stdin);
    unsigned int N,L,U;
    char a[100],b[100],c[100];
    while(cin>>N>>L>>U)
    {
        change(a,N);
        change(b,U);
        unsigned int l,sum=0,lena=strlen(a),lenb=strlen(b);
        l=lena>lenb?lenb:lena;
        for(int i=l-1; i>=0; i--)
        {
            if(a[i]=='1'&&b[i]=='1')
            {
                char c[100];
                strcpy(c,b);
                c[i]='0';
                for(int j=i-1; j>=0; j--)c[j]='1';
                unsigned int s=0;
                for(int j=0; j<lenb; j++)
                    s+=(c[j]-'0')*pow(2,j);
                if(s>=L)strcpy(b,c);
            }
        }
        for(int j=0; j<lenb; j++)
            sum+=(b[j]-'0')*pow(2,j);
        cout<<sum<<endl;
    }
    return 0;
}
