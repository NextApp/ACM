/*
ID: 15588661
PROG: friday
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int M[15]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int N;
    while(cin>>N)
    {
        int Day[7],s,sum=0;
        memset(Day,0,sizeof(Day));
        for(int i=0;i<N;i++)
        {
            s=1900+i;
            int ok=0,o=0;
            if(!(s%400)||(s%100&&!(s%4)))ok=1;
                for(int j=0;j<12;j++)
                {
                    Day[(sum+o+13)%7]++;
                    o+=M[j];
                    if(ok&&j==1)o++;
                }
                sum+=o;
        }
        cout<<Day[6]<<' ';
        for(int i=0;i<5;i++)
        cout<<Day[i]<<' ';
        cout<<Day[5]<<endl;
    }
    return 0;
}
