#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char m[102];
int main()
{
    while(cin>>m)
    {
        double h=(m[0]-'0')*10+(m[1]-'0');
        double s=(m[3]-'0')*10+(m[4]-'0');
        h=h*30+s*0.5;
        if(h>=360)h-=360;
        s=s*6;
        if(s>=360)s-=360;
        cout<<h<<' '<<s<<endl;
    }
    return 0;
}
