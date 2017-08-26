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
const int N=10007;
vector<pii>vec[N];
bool vis[N];
ll prim(ll a)
{
    priority_queue<pii, vector<pii> , greater<pii> >pq;
    pq.push(pii(0,a));
    ll cost=0;
    while(!pq.empty())
    {
        ll num1=pq.top().ff;
        ll num2=pq.top().ss;
        //cout<<num2<<"\t";
        pq.pop();
        if(vis[num2]==true)
            continue;
        cost+=num1;
        vis[num2]=true;
       // cout<<cost<<"\n";
        fr(i,0,vec[num2].size())
        {
            if(vis[vec[num2][i].ss]==false)
                pq.push(pii(vec[num2][i].ff,vec[num2][i].ss));
        }
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,x,y,cost,ans,i,j,cnt;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        y=0;
        fr(i,0,n)
        {
            cin>>s;
            cin>>cnt;
            y++;
            fr(j,0,cnt)
            {
                cin>>x>>cost;
                vec[y].pb(pii(cost,x));
                vec[x].pb(pii(cost,y));
            }
        }
        memset(vis,false,sizeof vis);
        ans=prim(1);
        cout<<ans<<"\n";
        frn(i,0,n)
        vec[i].clear();
    }
    return 0;
}
