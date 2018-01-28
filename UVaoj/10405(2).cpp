#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1005
using namespace std;
char a[N],b[N];
int d[N][N];
int main()
{
    while(gets(a)!=NULL)
    {
        gets(b);
        int lena=strlen(a),lenb=strlen(b);
        for(int i=lena; i>=0; i--)
            for(int j=lenb; j>=0; j--)
            {
                if(i==lena||j==lenb)d[i][j]=0;
                else
                {
                    if(a[i]==b[j])d[i][j]=d[i+1][j+1]+1;
                    else d[i][j]=max(d[i+1][j],d[i][j+1]);
                }
            }
        cout<<d[0][0]<<endl;
    }
    return 0;
}
