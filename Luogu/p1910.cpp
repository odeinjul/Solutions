#include<iostream>
#include<cmath>
using namespace std;
int n,m,x,f[1010][1010];
struct spiders
{
    int doc,dress,salary;
}spider[110];
int main()
{
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)
    {
        cin>>spider[i].doc>>spider[i].dress>>spider[i].salary;
    }
    for(int i=0;i<=x;i++)
        for(int j=0;j<=m;j++)
            f[i][j]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=0;j--)
        {
            for(int k=m;k>=0;k--)
            {
                if(j>=spider[i].salary&&k>=spider[i].dress)
                    f[j][k]=max(f[j][k],f[j-spider[i].salary][k-spider[i].dress]+spider[i].doc);
                else
                    f[j][k]=f[j][k];
            }
        }
    }
    cout<<f[x][m]<<endl;
    return 0;
}