#include<iostream>
using namespace std;
int main()
{
    int n,id=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long A,B;
        int ok=0;
        cin>>A>>B;
        if(B>A)B=A;
        if(A==B)ok=1;
        if(A%2&&B==1)
        {
            ok=1;
        }
        cout<<"Case "<<id++<<": ";
        if(!ok)cout<<"second"<<endl;
        else cout<<"first"<<endl;
    }
    return 0;
}
