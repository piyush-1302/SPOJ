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
vector<pii>vec[N];
ll dis[N];
void dij(ll a, ll b)
{
    priority_queue<pii, vector<pii>, greater<pii> >q;
    dis[a]=0;
    q.push(pii(dis[a],a));
    while(!q.empty())
    {
        ll num=q.top().ss;
        q.pop();
        fr(i,0,vec[num].size())
        {
            ll fr,bc;
            bc=vec[num][i].ff;
            fr=vec[num][i].ss;
            if(dis[fr]>dis[num]+bc)
            {
                dis[fr]=dis[num]+bc;
                q.push(pii(dis[fr],fr));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,t,x,y,i,j,b,a,w;
    cin>>t;
    //memset(dis,mod,sizeof dis);
    while(t--)
    {
    	cin>>n>>m>>a>>b;
        //cin>>n>>m>>a>>b;
        frn(i,0,N)
        {
            dis[i]=mod;
            vec[i].clear();
        }
        fr(i,0,m)
        {
            cin>>x>>y>>w;
            vec[x].pb(pii(w,y));
            vec[y].pb(pii(w,x));
        }
        dij(a,b);
        if(dis[b]>=mod)
            cout<<"NONE\n";
        else
           cout<<dis[b]<<"\n";
    }
    return 0;
}
