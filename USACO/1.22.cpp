/*
ID: 15588661
PROG: namenum
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
using namespace std;
char M[10000][100];
int Vis[10000];
char SSS[10][10]= {"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int main()
{
    ifstream findata ("dict.txt");
    int i=0;
    while(findata>>M[i++]);
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    char S[20];
    while(fin>>S)
    {
        memset(Vis,0,sizeof(Vis));
        for(int k=0; S[k]; k++)
        {
            for(int j=0; j<i; j++)
            {
                if(Vis[j])continue;
                int ok=0;
                for(int m=0; m<3; m++)
                    if(SSS[S[k]-'2'][m]==M[j][k])ok=1;
                if(!ok)Vis[j]=1;
            }
        }
        int len=strlen(S),okk=0;
        for(int j=0; j<i; j++)
            if(!Vis[j]&&len==strlen(M[j]))
            {
                fout<<M[j]<<endl;
                okk=1;
            }
        if(!okk)fout<<"NONE"<<endl;
    }
    findata.close();
    fin.close();
    fout.close();
    return 0;
}
