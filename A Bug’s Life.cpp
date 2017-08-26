#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
vector<int>adj[2007];
bool vis[2007];
int a[2007];
int flag=0,tc;
void bfs(int val)
{
    if(tc==0)
    {
        a[val]=0;
        tc=1;
    }
    else
    {
        a[val]=1;
        tc=0;
    }
    int pos;
    queue<int>q;
    q.push(val);
    vis[val]=true;
    while(!q.empty())
    {
        pos=q.front();
        q.pop();
        for(ll i=0;i<adj[pos].size();i++)
        {
            if(vis[adj[pos][i]]==false)
            {
                vis[adj[pos][i]]=true;
                if(a[pos]==1)
                    a[adj[pos][i]]=0;
                else
                    a[adj[pos][i]]=1;
                q.push(adj[pos][i]);
            }
            else if(vis[adj[pos][i]]==true)
            {
                if(a[pos]==1 && a[adj[pos][i]]==1)
                {
                    flag=1;
                    break;
                }
                else if(a[pos]==0 && a[adj[pos][i]]==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            break;
    }
}
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        flag=0;
        ll m,n,i;
        int x,y;
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        memset(vis,false,sizeof vis);
        memset(a,-1,sizeof a);
        for(i=1;i<=n;i++)
        {
            if(flag==1)
                break;
            if(vis[i]==false)
            {
                tc=0;
                bfs(i);
            }
            //adj[i].clear();
        }
        cout<<"Scenario #"<<j<<":"<<"\n";
        if(flag==0)
            cout<<"No suspicious bugs found!"<<"\n";
        else
            cout<<"Suspicious bugs found!"<<"\n";
        for(i=1;i<=n;i++)
            adj[i].clear();
    }
    return 0;
}

