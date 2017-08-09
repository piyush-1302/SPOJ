#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll> >gr[10007];
ll dis[10007];
bool vis[10007];
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
    //cin>>t;
   //while(t>0)
    //{
        scanf("%lld",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%lld%lld",&a,&b);
            gr[a].push_back(make_pair(b,1));
            gr[b].push_back(make_pair(a,1));
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
        }
        //cout<<m<<"\t"<<c<<"\n";
    printf("%lld\n",m);
    return 0;
}

