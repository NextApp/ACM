#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int>pos[26];
    for(int i=0; i<s1.size(); i++)
        pos[s1[i]-'a'].push_back(i);
    int p=0,w=1;
    for(int i=0; i<s2.size(); i++)
    {
        vector<int>&pp=pos[s2[i]-'a'];
        if(!pp.size())
        {
            w=-1;
            break;
        }
        else
        {
            vector<int>::iterator s=lower_bound(pp.begin(),pp.end(),p);
            if(s==pp.end())
            {
                w++;
                p=pp[0]+1;
            }
            else p=(*s)+1;
        }
        cout<<w<<endl;
    }
    return 0;
}
