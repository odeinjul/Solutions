#include<iostream>
using namespace std;
int n,s[250010],ans=0,top=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t,x;
        cin>>t>>x;
        while(x<=s[top])
        {
            if(x==s[top])ans++;
            top--;
        }
        s[++top]=x;
    }
    cout<<n-ans<<endl;
}  