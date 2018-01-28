#include<iostream>
#include<cmath>
using namespace std;
struct T
{
    int place;
    long long n;
} q[100050],p[100050];
int main()
{
    int num;
    while(cin>>num)
    {
        if(!num)break;
        else
        {
            long long n;
            int l=0,m=0;
            for(int i=0;i<num;i++)
            {
                cin>>n;
                if(n>=0)q[m].place=i,q[m++].n=n;
                else p[l].place=i,p[l++].n=n;
            }
            int i=0,j=0;
            long long sum=0;
            while(i<l)
            {
                if(q[j].n+p[i].n<0)
                {
                    sum+=q[j].n*(fabs(p[i].place-q[j].place));
                    p[i].n+=q[j].n;
                    j++;
                }
                else if(q[j].n+p[i].n==0)
                {
                    sum+=q[j].n*(fabs(p[i].place-q[j].place));
                    i++,j++;
                }
                else
                {
                    sum+=-p[i].n*(fabs(p[i].place-q[j].place));
                    q[j].n+=p[i].n;
                    i++;
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
