#include<iostream>
using namespace std;
int x1,y1,x2,y2,t,x,y;
char h,s,wind;
int main()
{
    cin>>x1>>y1>>x2>>y2;
    cin>>t;
    if(x1<x2)
    {
        h='E';
        x=x2-x1;
    }
    if(x1>x2)
    {
        h='W';
        x=x1-x2;
    }
    if(y1<y2)
    {
        s='N';
        y=y2-y1;
    }
    if(y1>y2)
    {
        s='S';
        y=y1-y2;
    }
    int xi=x,yi=y;
    for(int i=1;i<=t;i++)
    {
        cin>>wind;
        if(wind==h)
        {
            x--;
        }
        if(wind==s)
        {
            y--;
        }
        if(x==0)h='A';
        if(y==0)s='A';
    }
    if(h=='A'&&s=='A')
    {
        cout<<xi+yi<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}