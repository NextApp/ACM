#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200
using namespace std;
int a[N],b[N],num,n,place[N],snum;
char c;
void print(int cur)
{
    if(cur==n)
    {
        for(int i=0;i<n;i++)
        cout<<(char)place[i];
        cout<<endl;
        snum++;
        return ;
    }
    for(int i=0;i<num;i++)
    if(a[b[i]])
    {
        place[cur]=b[i];
        a[b[i]]--;
        print(cur+1);
        a[b[i]]++;
    }
}
int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    while(cin>>n)
    {
        char c;
        snum=num=0;
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            cin>>c;
            if(!a[c])b[num++]=c;
            a[c]++;
        }
        print(0);
        cout<<snum<<endl;
    }
    return 0;
}
