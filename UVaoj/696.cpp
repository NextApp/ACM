#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,S[540][540];
int main()
{
  //  freopen("1.txt","r",stdin);
    for(a=1; a<=500; a++)S[1][a]=S[2][a]=S[a][1]=S[a][2]=a;
    S[2][3]=3;
    for(int j=3; j<=500; j++)
        for(int i=3; i<=500; i++)
        {
            if(j%2==0)S[i][j]=S[i-1][j]+j/2;
            else
            {
                if(i%2)S[i][j]=S[i-1][j]+(j+1)/2;
                else S[i][j]=S[i-1][j]+j/2;
            }
        }
    while(cin>>a>>b)
    {
        if(!a&&!b)break;
        else
        {
            int s;
            if(a==2)
            {
                s=(b/4)*4;
                if(b%4>2)s+=4;
                else s+=(b%4)*2;
            }
            else if(b==2)
            {
                s=(a/4)*4;
                if(a%4>2)s+=4;
                else s+=(a%4)*2;
            }
            else s=S[a][b];
            cout<<s<<" knights may be placed on a "<<a<<" row "<<b<<" column board."<<endl;
        }
    }
    return 0;
}
