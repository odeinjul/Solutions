#include<iostream>
using namespace std;
int ca(int n)
{
    if(n==1)return 1;
    if(n==0)return 1;
    else return n*ca(n-1);
}
int main()
{
    int c[20][20];
    c[1][1]=1;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=i;j++)
        {
            c[i][j]=ca(i)/(ca(j)*ca(i-j));
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}