#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int S[550][550];
int main()
{
    for(int i=3;i<=500;i++)
    for(int j=3;j<=500;j++)
    S[i][j]=(i*j+1)/2;
    for(int i=1;i<=500;i++)S[1][i]=S[i][1]=i;
    for(int i=1;i<=500;i++)
    S[i][2]=S[2][i]=4*(i/4)+(i%4<=2?2*(i%4):4);
    int a,b;
 //   freopen("1.txt","r",stdin);
    while(cin>>a>>b)
    {
        if(!a&&!b)break;
        else
            cout<<S[a][b]<<" knights may be placed on a "<<a<<" row "<<b<<" column board."<<endl;
    }
    return 0;
}
