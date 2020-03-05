#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n;
int main()
{
    cin>>n;
    int map[n+1];
    for(int i=0;i<=n;i++)
    {
        map[i]=0;
    }
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i)
            {
            if(map[j]==1)
                map[j]=0;
            else 
                map[j]=1;
            }
            cout<<map[j];
        }
        cout<<endl;
    }
    return 0;
}