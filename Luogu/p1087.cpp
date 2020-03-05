#include<iostream>
#include<cmath>
using namespace std;
    int n;
    char a[1026];
void work(int l,int r)
{
    if(r>l)
    {
    work(l,(l+r)/2);
    work((l+r+1)/2,r);
    }
    int B=1,I=1;
    for(int i=l;i<=r;i++)
    {
        if(a[i]=='1')B=0;
        else I=0;
    }
        if(B)cout<<"B";
        else if(I)cout<<"I";
        else cout<<"F";
}
int main()
{
    cin>>n>>a;
    work(0,(1<<n)-1);
    return 0;
}