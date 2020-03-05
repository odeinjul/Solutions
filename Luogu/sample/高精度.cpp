#include<bits/stdc++.h>
using namespace std;
int input(int a[])
{
    char s[6000];
    cin>>s;
    int len=strlen(s);
    //cout<<len<<endl;
    for(int i=0;i<len;i++)
    {
        a[i]=s[len-i-1]-'0';
    }
    return len;
}
int output(int a[],int lena)
{
    for(int i=lena-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}
int compare(int a[],int lena,int b[],int lenb)
{
    if(lena>lenb)return 1;
    if(lenb>lena)return -1;
    for(int i=lena-1;i>=0;i--)
    {
        if(a[i]>b[i])return 1;
        if(b[i]>a[i])return -1;
    }
    return 0;
}
int accurate_plus(int a[],int lena,int b[],int lenb,int c[])
{
    int lenc=max(lena,lenb)+1;
    for(int i=0;i<lenc;i++)
    {
        c[i]=a[i]+b[i]+c[i];
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;
    }
    output(c,lenc);
    return lenc;
}
int accurate_minus(int a[],int lena,int b[],int lenb,int c[])
{
    if(lenb>lena||lena==lenb&&(compare(a,lena,b,lenb)==-1))
    {
        cout<<'-';
        swap(a,b);
        swap(lena,lenb);
    }
    int lenc=max(lena,lenb);
    for(int i=0;i<lenc;i++)
    {
        c[i]=c[i]+a[i]-b[i];;
        if(c[i<0])
        {
            c[i]=c[i]+10,c[i+1]=-1;
        }
    }
    while(c[lenc==0]&&lenc>1)lenc--;
    output(c,lenc);
    return lenc;
}
int accurate_multiply(int a[],int lena,int b[],int lenb,int c[])
{
    int lenc=lena+lenb-1;
    for(int i=0;i<lena;i++)
    {
        for(int j=0;j<lenb;j++)
        {
            c[i+j]=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    while(c[lenc+1]>0)lenc++;
    lenc++;
    output(c,lenc);
    return lenc;
}
int accurate_divide(int a[],int lena ,int b,int c[])
{
    int r,lenc;
    for(int i=lena-1;i>=0;i--)
    {
        r=r*10+a[i];
        c[i]=r/b;
        r=r%b;
    }
    lenc=lena;
    while(c[lenc]==0&&lenc>1)lenc--;
    output(c,lenc);
    cout<<r<<endl;
    return lenc;
}
int main()
{
    int a[6000],b[6000],c[6000],d;
    int lena=input(a);
    int lenb=input(b);
    cin>>d;
    accurate_plus(a,lena,b,lenb,c);
    accurate_minus(a,lena,b,lenb,c);
    accurate_multiply(a,lena,b,lenb,c);
    accurate_divide(a,lena,d,c);
    return 0;
}