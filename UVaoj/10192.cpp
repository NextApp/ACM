#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[120],b[120];
int d[120][120];
int main()
{
    int id=1;
    while(gets(a)!=NULL)
    {
        if(a[0]=='#')break;
        else
        {
            gets(b);
            int lena=strlen(a),lenb=strlen(b);
            for(int i=lena;i>=0;i--)
            for(int j=lenb;j>=0;j--)
            {
                if(i==lena||j==lenb)d[i][j]=0;
                else if(a[i]==b[j])d[i][j]=d[i+1][j+1]+1;
                else d[i][j]=max(d[i][j+1],d[i+1][j]);
            }
            cout<<"Case #"<<id++<<": you can visit at most "<<d[0][0]<<" cities."<<endl;
        }
    }
    return 0;
}
