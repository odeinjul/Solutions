#include<iostream>
#include<string>
using namespace std;
string in;
int map[4][4];
int main()
{
    cin>>in;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        map[i][j]=0;
    }
    //cout<<in[0]<<endl;
    for(int i=0;i<in.length();i++)
    {
        in[i]-='0';
        if(in[i]==3||in[i]==6||in[i]==9)
        {
            map[in[i]/3][(in[i]-1)%3+1]=(i%2)+1;
            continue;
        }
        map[in[i]/3+1][(in[i]-1)%3+1]=(i%2)+1;
        //a:1 uim:2
    }
    //for(int i=0;i<4;i++)
    //{
    //    for(int j=0;j<4;j++)
    //        cout<<map[i][j]<<' ';
    //    cout<<endl;
    //}
    if((map[1][1]==map[1][2])&&(map[1][2]==map[1][3])&&(map[1][3]!=0))
    {
        //cout<<999<<endl;
        if(map[1][1]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[2][1]==map[2][2])&&(map[2][2]==map[2][3])&&(map[2][3]!=0))
    {
        //cout<<888<<endl;
        if(map[2][1]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[3][1]==map[3][2])&&(map[3][2]==map[3][3])&&(map[3][3]!=0))
    {
        //cout<<777<<endl;
        if(map[3][1]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[1][1]==map[2][1])&&(map[2][1]==map[3][1])&&(map[3][1]!=0))
    {
        //cout<<666<<endl;
        if(map[1][1]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[1][2]==map[2][2])&&(map[2][2]==map[3][2])&&(map[3][2]!=0))
    {
        //cout<<555<<endl;
        if(map[1][2]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[1][3]==map[2][3])&&(map[2][3]==map[3][3])&&(map[3][3]!=0))
    {
        //cout<<444<<endl;
        if(map[1][3]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[1][1]==map[2][2])&&(map[2][2]==map[3][3])&&(map[3][3]!=0))
    {
        ///cout<<333<<endl;
        if(map[1][1]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else if((map[1][3]==map[2][2])&&(map[2][2]==map[3][1])&&(map[3][1]!=0))
    {
        //cout<<222<<endl;
        if(map[1][3]==1)
        {
            cout<<"xiaoa wins."<<endl;
             
        }
        else
        {
            cout<<"uim wins."<<endl;
             
        }
    }
    else
    {
        cout<<"drew."<<endl;
    }
    return 0;
}