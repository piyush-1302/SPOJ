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
const int N=10007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    fr(k,1,t+1)
    {
        vector<ll>adj[N];
        bool vis[N];
        priority_queue<pii , vector<pii>, greater<pii> >pq;
        ll n,r,x,y;
        cin>>n>>r;
        ll indeg[N];
        memset(vis,false,sizeof(vis));
        memset(indeg,0,sizeof(indeg));
        fr(i,0,r)
        {
            cin>>y>>x;
            adj[x].pb(y);
            indeg[y]++;
        }
        fr(i,0,n)
        {
            if(indeg[i]==0)
            {
                pq.push(pii(1,i));
                vis[i]=true;
            }
        }
        cout<<"Scenario #"<<k<<":\n\n";
        while(!pq.empty())
        {
            ll ranks=pq.top().ff;
            ll node=pq.top().ss;
            cout<<ranks<<" "<<node<<"\n\n";
            pq.pop();
            fr(i,0,adj[node].size())
            {
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0 && vis[adj[node][i]]==false)
                {
                    pq.push(pii(ranks+1,adj[node][i]));
                    vis[adj[node][i]]=true;
                }
            }
        }
    }
    return 0;
}
