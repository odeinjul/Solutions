#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;
int n;
string in[102],in1[102];
int cmp(string a,string b)
{
    if(a.length()>b.length())
    {
        return 1;
    }
    else if(a.length()<b.length())
    {
        return 0;
    }
    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(a[i]>b[i])
            {
                return 1;
            }
            else if(a[i]<b[i])
            {
                return 0;
            }
            else 
            {
                continue;
            }
            
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
        in1[i]=in[i];
    }
    sort(in,in+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(in1[i]==in[0])
        {
            cout<<i+1<<endl;
            break;
        }
    }
    cout<<in[0]<<endl;
    return 0;
}