int N;
int fa[N];
int find(int x)
{
    if(x==fa[x])return x;
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
inline int find1(int x){return x==fa[x]?x:fa[x]=find1(fa[x]);}
int size[N];
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(size[xx]<size[yy])swap(xx,yy);//小并大
    fa[yy]=xx;size[xx]+=size[yy];
}

//另一种方法
f[i]为负数表示其根的负数
否则表示其size