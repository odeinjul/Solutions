#include<iostream>
#include<string>
using namespace std;
string input;
long long n[40],k,map[11][11],cnt[11],ans[1000];
int main()
{
    cin>>input>>k;
    for(int i=0;i<input.length();i++)
    {
        n[i]=input[i]-'0';
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        map[x][y]=1;
    }
    for(int k=0;k<=9;k++)
    {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(map[i][k]&&map[k][j])map[i][j]=1;
            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        map[i][i]=1;
        for(int j=0;j<=9;j++)
        {
            if(map[i][j])cnt[i]++;
        }
    }
    int z=0;
    ans[0]=1;
    for(int i=0;input[i];i++)//高精
    {
        z=0;
        int x=cnt[n[i]];
        for(int i=0;i<500;i++)
        {
            ans[i]=(ans[i]*x+z);
            z=ans[i]/10;
            ans[i]%=10;
        }
    }
    int i=500;
    while(ans[i]==0)i--;
    for(;i>=0;i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}