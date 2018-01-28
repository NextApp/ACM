#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M[1200000],Vis[1200000];
int main()
{
    int num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int m,n,ok=1,N,mm=0,ss=0;
        cin>>m>>n;
        memset(Vis,0,sizeof(Vis));
        for(int j=0; j<n; j++)
        {
            cin>>N;
            if(!N)M[ss++]=0;
            else if(N&&ok)
            {
                while(M[mm])mm++;
                if(ss<=mm)ok=0;
                if(!Vis[N])M[mm++]=N;
                else
                {
                    if(Vis[N]<=mm)M[mm++]=N;
                    else
                    {
                        int k=Vis[N],okk=0;
                        for(; k<ss; k++)
                            if(!M[k])
                            {
                                M[k]=N;
                                okk=1;
                                break;
                            }
                        if(!okk)ok=0;
                    }
                }
                Vis[N]=ss;
            }
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int j=0; j<ss-1; j++)
                cout<<M[j]<<' ';
            cout<<M[ss-1]<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
