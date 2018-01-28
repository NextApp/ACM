#include<iostream>
#include<cstdio>
#include<queue>
#define N 100
using namespace std;
typedef struct
{
    int a,b;
}Node;
struct cmp
{
    bool operator()(const Node &a,const Node &b)
    {
        return a.b>b.b;
    }
};
int main()
{
    int n;
    cout<<"输入n"<<endl;
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            priority_queue<int>Q;
            int a[N];
            cout<<"输入一组长度为n的整数："<<endl;
            for(int i=0; i<n; i++)
            {
                cin>>a[i];
                Q.push(a[i]);
            }
            cout<<Q.size()<<endl;
            cout<<"排序后:"<<endl;
            while(!Q.empty())
            {
                cout<<Q.top()<<' ';
                Q.pop();
            }
            cout<<endl;
            priority_queue<int>T(a,a+n);
            while(!T.empty())
            {
                cout<<T.top()<<' ';
                T.pop();
            }
            cout<<endl;
            cout<<"按1继续测试结构体的优先级队列:"<<endl;
            int ok;cin>>ok;
            if(ok)
            {
                cout<<"输入n"<<endl;
                int n;
                cin>>n;
                cout<<"输入n个结构体数据:"<<endl;
                Node *arr=new Node[n];
                for(int i=0;i<n;i++)cin>>arr[i].a>>arr[i].b;
                priority_queue<Node,vector<Node>,cmp>Q(arr,arr+n);
                cout<<"按照cmp排序结果为:"<<endl;
                while(!Q.empty())
                {
                    Node u=Q.top();
                    cout<<u.a<<' '<<u.b<<endl;
                    Q.pop();
                }
            }
        }
    }
    return 0;
}
