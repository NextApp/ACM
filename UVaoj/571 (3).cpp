#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int k,m,n;
char S[10][10];
int main()
{
    strcpy(S[0],"fill A");
    strcpy(S[1],"empty A");
    strcpy(S[2],"fill B");
    strcpy(S[3],"empty B");
    strcpy(S[4],"pour A B");
    strcpy(S[5],"pour B A");
    while(cin>>m>>n>>k)
    {
        int a=0,b=0,o=0;
        while(1)
        {
            if(!a)
            {
                cout<<S[0]<<endl;
                a=m;
            }
            else
            {
                cout<<S[4]<<endl;
                b+=a;
                a=0;
            }
            if(b==k)
            {
                cout<<"success"<<endl;
                break;
            }
            if(b>=n)
            {
                a=b-n;
                cout<<S[3]<<endl;
                b=0;
            }
        }
    }
    return 0;
}
