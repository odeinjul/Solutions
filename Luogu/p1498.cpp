#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
    char map[2200][2200];
void copy_u(int b)
{
        int a=pow(2,b-1);
        for(int j=a+1;j<=2*a;j++)
            for(int i=a+1;i<=3*a;i++)
            {
                map[j][i]=map[j-a][i-a];
            }
        /* 
        for(int k=a*2;k>=1;k--)
        {
            for(int j=1;j<=a*2;j++)
            {
                cout<<map[k][j];
            }
            cout<<endl;
        }
        cout<<endl<<b<<"-------------"<<endl;
        */
}
void copy_r(int n)
{
        int a=pow(2,n);
        for(int j=1;j<=a;j++)
            for(int i=a+1;i<=a*2;i++)
            {
                map[j][i]=map[j][i-a];
            }

}
int main()
{
    cin>>n;
    memset(map,' ',sizeof(map));
    map[1][1]='/';
    map[1][2]='_';
    map[1][3]='_';
    map[1][4]='\\';
    map[2][2]='/';
    map[2][3]='\\';
    for(int i=2;i<=n;i++)
    {
        copy_r(i);
        copy_u(i);
    }
int a=pow(2,n);
    for(int k=a;k>=1;k--)
    {
        for(int j=1;j<=a*2;j++)
        {
            cout<<map[k][j];
        }
        cout<<endl;
    }
    //cout<<'\\'<<'/'<<endl;
    return 0;
}