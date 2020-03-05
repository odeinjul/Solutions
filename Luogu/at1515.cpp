#include<iostream>
using namespace std;
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double aa=b/a,bb=d/c;
    if(aa>bb)
    cout<<"TAKAHASHI"<<endl;
    else if(aa<bb)
    cout<<"AOKI"<<endl;
    else
    cout<<"DRAW"<<endl;
    return 0;
}