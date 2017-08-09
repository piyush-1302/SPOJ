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
const int N=100007;
vector<int>adj[N];
bool vis[N];
queue<ll>q;
void dfs(ll a)
{
    if(vis[a]==true)
        return ;
    vis[a]=true;
    fr(i,0,adj[a].size())
    {
        dfs(adj[a][i]);
    }
    q.push(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,i,j,indeg[N],ts[N],x,y,k=0,t,cnt;
    cin>>t;
    fr(k,1,t+1)
    {
        cin>>n>>m;
        fr(i,0,N)
        {
            adj[i].clear();
            vis[i]=false;
            indeg[i]=0;
        }
        fr(i,0,m)
        {
            cin>>x>>y;
            adj[x].pb(y);
            indeg[y]++;
        }
        fr(i,0,n)
        {
            if(indeg[i]==0)
                dfs(i);
        }
        cnt=1;
        cout<<"Scenario #"<<k<<":"<<endl<<endl;
        while(!q.empty())
        {
            cout<<cnt<<" "<<q.front()<<"\n\n";
            q.pop();
            cnt++;
        }
    }
    return 0;
}
