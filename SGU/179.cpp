#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char m[12000];
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>m)
    {
        int len=strlen(m);
        int num=0,ok=0;
        for(int i=len-1;i>=0;i--)
        {
            if(i>=0&&m[i-1]=='('&&m[i]==')')
            {
                i--;
                num++;
                continue;
            }
            ok=1;
            int k=i;
            while(k>=0&&m[k]==')')
            {
                k--;
            }
            m[k]=')';
            int s=0;
            for(int j=0;j<=k;j++)
                    cout<<m[j];
            for(int j=0;j<num+1;j++)
            cout<<'(';
            for(int j=0;j<(len-(k+2+num));j++)
            cout<<')';
            cout<<endl;
            break;
        }
        if(!ok)cout<<"No solution"<<endl;
    }
    return 0;
}
