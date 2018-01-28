#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define N 1200000
using namespace std;
int main()
{
   // freopen("1.txt","r",stdin);
    string s;
    while(cin>>s)
    {
        vector<int>pos[26];
        for(int i=0;i<s.size();i++)
        pos[s[i]-'a'].push_back(i);
        int p=0,a[30],ok=0;
        memset(a,0,sizeof(a));
        for(int i=25;i>=0;i--)
        {
            vector<int>&o=pos[i];
            if(!ok)
            {
                if(pos[i].size())
                {
                    p=o[o.size()-1]+1;
                    a[i]=o.size();
                    ok=1;
                }
            }
            else if(pos[i].size())
            {
                vector<int>::iterator it=lower_bound(o.begin(),o.end(),p);
                if(it!=o.end())
                {
                    a[i]=o.end()-it;
                    p=o[o.size()-1]+1;
                }
            }
        }
        for(int i=25;i>=0;i--)
        while(a[i]>0)
        {
            cout<<char('a'+i);
            a[i]--;
        }
        cout<<endl;
    }
    return 0;
}
