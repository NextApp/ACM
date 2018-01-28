/*
ID: 15588661
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int Vis[1000];
int main()
{
    int num;
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    char M[1000][20],C[100];
    memset(Vis,0,sizeof(Vis));
    cin>>num;
    for(int i=0; i<num; i++)
        cin>>M[i];
    while(cin>>C)
    {
        int money,n;
        char D[400];
        cin>>money>>n;
        for(int i=0; i<num; i++)
            if(!strcmp(C,M[i]))
            {
               if(n)Vis[i]-=(money/n)*n;
                break;
            }
        for(int i=0; i<n; i++)
        {
            cin>>D;
            for(int j=0; j<num; j++)
                if(!strcmp(D,M[j]))
                {
                    Vis[j]+=money/n;
                    break;
                }
        }
    }
    for(int i=0;i<num;i++)
    cout<<M[i]<<' '<<Vis[i]<<endl;
    return 0;
}
