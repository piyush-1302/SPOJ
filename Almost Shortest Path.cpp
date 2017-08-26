#include<bits/stdc++.h>
/*#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<math>
#include<set>
#include<iterator>
#include<tuple>
#include<limit>*/
using namespace std;
#define ll int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define mod 1000000007
#define pii pair<ll,ll>
const int N=1007;
vector<pii>adj[N];
vector<pii>avoid;
ll parentkaparent[N];
bool vis[N];
ll dis[N];

void edgestore(ll node, ll parent)
{
    //cout<<node<<"\t"<<parent<<"\n";
    while(parent!=-1)
    {
        avoid.pb(pii(parent,node));
        node=parent;
        parent=parentkaparent[parent];
    }
}

void dij1(ll a, ll b)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(pii(0,a));
    dis[a]=0;
    while(!pq.empty())
    {
        ll parent=pq.top().ss;
       // cout<<parent<<"\n\n";
        pq.pop();
        fr(i,0,adj[parent].size())
        {
            ll weight=adj[parent][i].ff;
            ll node=adj[parent][i].ss;
           // cout<<"NODE  PARENT "<<node<<"\t"<<parent<<"\n";
            if(node==b)
            {
                if(dis[node]==dis[parent]+weight)
                {
                    edgestore(node,parent);
                    continue;
                }
            }
            if(dis[node]>weight+dis[parent])
            {
                dis[node]=dis[parent]+weight;
                parentkaparent[node]=parent;
                pq.push(pii(dis[node],node));
                if(node==b)
                {
                    avoid.clear();
                    edgestore(node,parent);
                }
            }
        }
    }
}

void dij2(ll a, ll b)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(pii(0,a));
    dis[a]=0;
    while(!pq.empty())
    {
        ll parent=pq.top().ss;
        pq.pop();
        fr(i,0,adj[parent].size())
        {
            ll node=adj[parent][i].ss;
            ll weight=adj[parent][i].ff;
            if(find(avoid.begin(),avoid.end(),pii(parent,node))==avoid.end())
            {
                if(dis[node]>dis[parent]+weight)
                {
                    dis[node]=dis[parent]+weight;
                    pq.push(pii(dis[node],node));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll i,x,y,w,n,m,flag=1,d,s;
    while(flag)
    {
        cin>>n>>m;
        if(n==0 && m==0)
        {
            flag=0;
            break;
        }
        cin>>s>>d;
        fr(i,0,N)
        {
            adj[i].clear();
            //vis[i]=false;
            dis[i]=10000000;
            //avoid.clear();
            parentkaparent[i]=-1;
        }
        fr(i,0,m)
        {
            cin>>x>>y>>w;
            adj[x].pb(pii(w,y));
        }
        /*frn(i,0,n)
        	cout<<adj[i].size()<<"\n";*/
        dij1(s,d);
        if(dis[d]==10000000)
        {
            cout<<"-1\n";
            continue;
        }
        fr(i,0,N)
        {
            dis[i]=10000000;
            parentkaparent[i]=-1;
            //vis[i]=false;
        }
        dij2(s,d);
        if(dis[d]==10000000)
            cout<<"-1\n";
        else
            cout<<dis[d]<<"\n";
    }
    return 0;
}
