#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int k,l,n;
char M[40000][10],vis[126];
void print(int cur,char a[])
{
    cout<<"writeln(";
    for(int i=0; i<cur-1; i++)
        cout<<a[i]<<',';
    cout<<a[n-1]<<")"<<endl;
}
int dfs(int cur,char a[],int len)
{
    if(cur==n)
    {
        for(int i=0; i<2*cur; i++)
            cout<<' ';
        print(cur,a);
    }
    else
    {
        char c;
        int l=len;
        for(int j=0; j<=cur; j++)
            if(!vis['a'+j])
            {
                c='a'+j;
                break;
            }
        for(int i=cur; i>=0; i--)
        {
            char b[100];
            strcpy(b,a);
            for(int j=cur; j>=i; j--)
                b[j+1]=b[j];
            b[i]=c;
            if(cur)
            {
                l+=2;
                for(int s=0; s<2*cur; s++)cout<<' ';
                if(i==cur)cout<<"if "<<b[i-1]<<" < "<<b[i]<<" then"<<endl;
                else if(!i)cout<<"else"<<endl;
                else cout<<"else if "<<b[i-1]<<" < "<<b[i]<<" then"<<endl;
            }
            b[cur+1]='\0';
            vis[c]=1;
            dfs(cur+1,b,l);
            vis[c]=0;
        }
    }
}
int main()
{
    //  freopen("1.txt","r",stdin);
    int casenum;
    cin>>casenum;
    for(int num=0; num<casenum; num++)
    {
        cin>>n;
        if(num)cout<<endl;
        cout<<"program sort(input,output);"<<endl<<"var"<<endl;
        for(int i=0; i<n-1; i++)
            cout<<char('a'+i)<<',';
        cout<<char('a'+n-1)<<" : integer;"<<endl;
        cout<<"begin"<<endl;
        cout<<"  readln(";
        for(int i=0; i<n-1; i++)
            cout<<char('a'+i)<<',';
        cout<<char('a'+n-1);
        cout<<");"<<endl;
        memset(vis,0,sizeof(vis));
        l=0;
        char a[100];
        dfs(0,a,2);
        cout<<"end."<<endl;
    }
    return 0;
}
