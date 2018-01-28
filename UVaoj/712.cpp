#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,id=1;
    while(cin>>n)
    {
        if(!n)return 0;
        else
        {
            int P[10];
            char c,S[10],a[200];
            for(int i=0; i<n; i++)
                cin>>c>>P[i];
            cin>>a;
            int m;
            cin>>m;
            cout<<"S-Tree #"<<id++<<":"<<endl;
            for(int i=0; i<m; i++)
            {
                int k=0,d=0;
                cin>>S;
                for(int j=n-1; j>=0; j--)
                    d+=(S[P[j]-1]-'0')*pow(2,k++);
                cout<<a[d];
            }
            cout<<endl<<endl;
        }
    }
    return 0;
}
