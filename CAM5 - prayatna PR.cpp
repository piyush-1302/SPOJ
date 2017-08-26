#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
vector<int>adj[100007];
bool vis[100007];
int bfs(ll pos)
{
    queue<ll>q;
    q.push(pos);
    vis[pos]=true;
    while(!q.empty())
    {
        ll val;
        val=q.front();
        q.pop();
        for(ll i=0;i<adj[val].size();i++)
        {
            if(vis[adj[val][i]]==false)
            {
                vis[adj[val][i]]=true;
                q.push(adj[val][i]);
            }
        }
    }
}
int main()
{
    ll t,n,m,i,x,y,cnt;
    scanf("%lld",&t);
    while(t--)
    {
        cnt=0;
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld%lld",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        memset(vis,false,sizeof vis);
        for(i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                //cout<<"I==   "<<i<<"\n";
                cnt++;
                bfs(i);
            }
            adj[i].clear();
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
