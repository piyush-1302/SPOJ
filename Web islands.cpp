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
#include<tuple>*/
using namespace std;
#define ll long long int
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
const int N=100007;
vector<ll>graph[N];
vector<ll>revgraph[N];
stack<ll>st;
bool vis[N];
ll ans[N];
vector<ll>temp;
void dfs(ll src)
{
    vis[src]=true;
    fr(i,0,graph[src].size())
    {
        if(!vis[graph[src][i]])
            dfs(graph[src][i]);
    }
    st.push(src);
}
ll dfsrev(ll src,ll com)
{
    vis[src]=true;
    ans[src]=com;
    ll id=src;
    fr(i,0,revgraph[src].size())
    {
        if(!vis[revgraph[src][i]])
            id=min(id,dfsrev(revgraph[src][i],com));
    }
    return id;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,x,y;
    cin>>n>>m;
    fr(i,0,m)
    {
        cin>>x>>y;
        graph[x].pb(y);
        revgraph[y].pb(x);
    }
    memset(vis,false,sizeof(vis));
    fr(i,0,n)
    {
        if(!vis[i])
            dfs(i);
    }
    memset(vis,false,sizeof(vis));
    ll com=0;
    while(!st.empty())
    {
        ll ele=st.top();
        ll val;
        st.pop();
        if(!vis[ele])
        {
            val=dfsrev(ele,com++);
            temp.pb(val);
        }
    }
    fr(i,0,n)
    {
        ll j=ans[i];
        cout<<temp[j]<<"\n";
    }
    return 0;
}
