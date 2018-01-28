#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int M[10100],S[10100];
int main()
{
    int m,n,id=1;
    while(cin>>m>>n)
    {
        if(!m&&!n)break;
        else
        {
            memset(M,0,sizeof(M));
            for(int i=0; i<m; i++)
                cin>>S[i];
            sort(S,S+m);
            for(int i=0; i<m; i++)
                if(!M[S[i]])
                {
                    M[S[i]]=i+1;
                }
            cout<<"CASE# "<<id++<<":"<<endl;
            for(int i=0; i<n; i++)
            {
                int b;
                cin>>b;
                if(M[b])cout<<b<<" found at "<<M[b]<<endl;
                else cout<<b<<" not found"<<endl;
            }
        }
    }
    return 0;
}
