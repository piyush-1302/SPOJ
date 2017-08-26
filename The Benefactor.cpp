#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
vector<pair<ll,ll> >gr[50007];
ll dis[50007];
bool vis[50007];
void bfs(ll a)
{
    ll i,u,v,w;
    vis[a]=true;
    for(i=0;i<gr[a].size();i++)
    {
        //cout<<"\nINBFSLOOP\t";
        u=gr[a][i].first;
        v=gr[a][i].second;
        //cout<<a<<"\t"<<u<<"\t"<<v<<"\t"<<vis[u];
        if(vis[u]==false)
        {
            dis[u]=dis[a]+v;
            //cout<<"\nEVENMOREINSIDE\t"<<a<<"\t"<<dis[a]<<"\t"<<dis[u];
            bfs(u);
        }
    }
}
int main()
{
    ll t,n,i,a,b,w,m,c;
    cin>>t;
    while(t>0)
    {
        scanf("%lld",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&w);
            gr[a].pb(mp(b,w));
            gr[b].pb(mp(a,w));
        }
        memset(vis,false,sizeof vis);
        memset(dis,0,sizeof dis);
        bfs(1);
        m=-1;
        c=0;
        for(i=1;i<=n;i++)
        {
            //cout<<"EXECUTING !FOR LOOP\n";
            //cout<<dis[i]<<"\t";
            if(dis[i]>m)
            {
                m=dis[i];
                c=i;
            }
        }
        //cout<<m<<"\t"<<c<<"\n";
        memset(vis,false,sizeof vis);
        memset(dis,0,sizeof dis);
        bfs(c);
        m=-1;
        c=0;
        for(i=1;i<=n;i++)
        {
            //cout<<"EXECUTING @ FOOR LOOP\n";
            //cout<<dis[i]<<"\t";
            if(dis[i]>m)
            {
                m=dis[i];
                c=i;
            }
        gr[i].clear();
        }
        //cout<<m<<"\t"<<c<<"\n";
    printf("%lld\n",m);
    t--;
    }
    return 0;
}


