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
vector<int>adj[N];
bool vis[N];
priority_queue<ll, vector<ll>, greater<ll> >q;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,i,j,indeg[N],ts[N],x,y,k=0;
    cin>>n>>m;
    for(i=0;i<=n;i++)
    {
        vis[i]=false;
        indeg[i]=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            vis[i]=true;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll temp=q.top();
        q.pop();
        ts[k]=temp;
        k++;
        for(j=0;j<adj[temp].size();j++)
        {
            indeg[adj[temp][j]]--;
            if(indeg[adj[temp][j]]==0 && vis[adj[temp][j]]==false)
            {
                vis[adj[temp][j]]=true;
                q.push(adj[temp][j]);
            }
        }
    }
    if(k!=n)
    {
        cout<<"Sandro fails.\n";
        return 0;
    }
    for(i=0;i<n;i++)
        cout<<ts[i]<<" ";
    cout<<"\n";
    return 0;
}


