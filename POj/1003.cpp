#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    float m;
    while(cin>>m)
    {
        if(!m)break;
        else
        {
            float sum=0;
            int num=0,i=2;
            do
            {
                sum+=1./i++;
                num++;
            }while(sum<m);
            cout<<num<<" card(s)"<<endl;
        }
    }
    return 0;
}
