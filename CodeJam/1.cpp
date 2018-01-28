#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char S[]={"yhesocvxduiglbkrztnwjpfmaq"};
int main()
{
    int T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("2.txt","w",stdout);
    char a[120],b[120],vis[140];
    cin>>T;
    getchar();
    memset(vis,0,sizeof(vis));
    for(int k=1;k<=T;k++)
    {
        gets(a);
        cout<<"Case #"<<k<<": ";
        for(int i=0;a[i];i++)
        if(a[i]!=' ')cout<<S[a[i]-'a'];
        else cout<<' ';
        cout<<endl;
    }
    return 0;
}
