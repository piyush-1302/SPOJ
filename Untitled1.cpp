#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#include<cmath>

#define f(i,a,b) for(int i=a;i<b;i++)
#define b(i,a,b) for(int i=a;i>b;i--)
#define mpr(a,b) make_pair(a,b)
#define pr pair<int,int>
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define newline printf("\n")
#define ll long long
using namespace std;
int vis[1005][1005];
int dist[1005][1005];
char graph[1005][1005];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
void bfs(int i,int j)
{
    queue<pr> q;
    q.push(mpr(i,j));
    dist[i][j]=0;
    vis[i][j]=1;
    pr t;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        int t1=t.first;
        int t2=t.second;
        f(k,0,4)
        {
            if(graph[t1+x[k]][t2+y[k]]=='.'&&vis[t1+x[k]][t2+y[k]]==0)
            {
                dist[t1+x[k]][t2+y[k]]=dist[t1][t2]+1;
                q.push(mpr(t1+x[k],t2+y[k]));
                vis[t1+x[k]][t2+y[k]]=1;
            }
        }
    }
}
void ini()
{
    f(i,0,1005)
    {
        f(j,0,1005)
        {
            dist[i][j]=0;
            vis[i][j]=0;
        }
    }
}
void disp(int u[1005][1005],int c,int r)
{
    f(i,0,c)
    {
        f(j,0,r)
        {
            cout<<u[i][j]<<" ";
        }
        newline;
    }
}
main()
{
    //ios_base::sync_with_stdio(false);
    //freopen("inp.txt","r",stdin);
    int t;
    si(t);
    while(t--)
    {
        int c,r;
        pr f;
        si(r);si(c);
        f(i,0,c)
            ss(graph[i]);
        ini();
        f(i,0,c)
        {
            f(j,0,r)
            {
                if(graph[i][j]=='.')
                    {f=mpr(i,j);i=c+1;break;}
            }
        }
        //cout<<f.first<<" "<<f.second<<"\n";
        bfs(f.first,f.second);
        int ma=0;
        f(i,0,c)
        {
            f(j,0,r)
            {
                if(ma<dist[i][j])
                {
                    f=mpr(i,j);
                    ma=dist[i][j];
                }
            }
        }//disp(dist,c,r);
        //cout<<f.first<<" "<<f.second<<"\n";
        ini();
        bfs(f.first,f.second);ma=0;
        f(i,0,c)
            f(j,0,r)
                ma=max(dist[i][j],ma);
        printf("Maximum rope length is %d.\n",ma);
    }
}
