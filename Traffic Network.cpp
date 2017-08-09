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
#include<set>
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
const int N=100007;
vector<pii>vecfor[N],vecback[N];
ll dis1[N],dis2[N];
void dij(ll a, vector<pii> *vec, ll *dis)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(pii(0,a));
    dis[a]=0;
    while(!pq.empty())
    {
        ll num=pq.top().ss;
        ll num1,num2;
       //cout<<num<<"\n";
        pq.pop();
        fr(i,0,vec[num].size())
        {
            num1=vec[num][i].ff;
            num2=vec[num][i].ss;
            //cout<<num1<<"\t"<<num2<<"\n";
            //cout<<dis[num2]<<"\t"<<dis[num]+num1<<"\n";
            if(dis[num2]>dis[num]+num1)
            {
                dis[num2]=dis[num]+num1;
                pq.push(pii(dis[num2],num2));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,e,k,s,d,i,j,ans,x,y,w;
    cin>>t;
    while(t--)
    {
        fr(i,0,N)
        {
            vecfor[i].clear();
            vecback[i].clear();
            dis1[i]=mod;
            dis2[i]=mod;
        }
        cin>>n>>e>>k>>s>>d;
        fr(i,0,e)
        {
            cin>>x>>y>>w;
            vecfor[x].pb(pii(w,y));
            vecback[y].pb(pii(w,x));
        }
        dij(s,vecfor,dis1);
        dij(d,vecback,dis2);
        ans=mod;
        /*fr(i,0,n)
        {
            cout<<dis1[i+1]<<"\t"<<dis2[i+1]<<"\n";
        }*/
        while(k--)
        {
            cin>>x>>y>>w;
            ans=min(ans,min(dis1[d],min(dis1[x]+w+dis2[y],dis1[y]+w+dis2[x])));
        }
        if(ans>=mod)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}
