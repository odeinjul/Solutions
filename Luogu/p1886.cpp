#include<iostream>
#include<deque>
using namespace std;
int n,k;
struct node
{
    int num,code;
}input[1000010];
int maxn[1000010],minn[1000010],front=0;
int main()
{
    cin>>n>>k;
    deque<node> b,s;//big/small
    for(int i=1;i<=n;i++)
    {
        cin>>input[i].num;
        input[i].code=i;
    }
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&input[i].num<s.back().num)
        {    
            s.pop_back();
        }
        //if(!s.empty())
        //cout<<s.back()<<' '<<input[i]<<endl;
        s.push_back(input[i]);
        while(s.size()>k||s.front().code<i-k)s.pop_front();
        cout<<s.front().num<<' '<<s.front().code<<' '<<i<<endl;
        if(i>=k)
            cout<<s.front().num<<' ';
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        while(!b.empty()&&input[i].num>b.back().num)
        {        
            b.pop_back();
        }
        b.push_back(input[i]);
        while(b.size()>k||b.front().code<i-k)b.pop_front();
        if(i>=k)
            cout<<b.front().num<<' ';
    }
    cout<<endl;
    return 0;
}