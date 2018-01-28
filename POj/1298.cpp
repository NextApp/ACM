#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a[100];char b[]="START",c[]="END",d[]="ENDOFINPUT";
    while(gets(a)!=NULL)
    {
        if(!strcmp(a,d))break;
        else if(!strcmp(a,b))
        {
            char e[300],x;
            gets(e);
            for(int i=0;e[i];i++)
            {
                if(e[i]>='F'&&e[i]<='Z')
                x=e[i]-5,cout<<x;
                else if(e[i]<'F'&&e[i]>='A')
                x=e[i]+21,cout<<x;
                else cout<<e[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
