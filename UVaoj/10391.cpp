#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[130000][100];
int main()
{
    int i=0;
    //freopen("1.txt","r",stdin);
    while(cin>>a[i])i++;
    for(int j=1; j<i; j++)
    {
        for(int k=j-1; k>=0; k--)
        {
            int ok=1,m;
            if(a[k][0]!=a[j][0])break;
            for(m=0; a[k][m]; m++)
                if(a[j][m]!=a[k][m])ok=0;
            if(ok)
            {
                char c[100];
                strcpy(c,a[j]+m);
                //if(!strcmp(a[k],c))continue;
                int q=0,l,p=i-1,OK=0;
                while(q<p)
                {
                    l=(q+p)/2;
                    if(!strcmp(c,a[l])||!strcmp(a[p],c)||!strcmp(a[q],c))
                    {

                        OK=1;
                        break;
                    }
                    else if(strcmp(c,a[l])>0)q=l+1;
                    else p=l-1;
                }
                if(OK){cout<<a[j]<<endl;break;}
            }
        }
    }
    return 0;
}
