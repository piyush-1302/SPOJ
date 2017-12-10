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
const int N=400007;
ll bit[N],ans[N];
void add(ll x)
{
    while(x<=100000)
    {
        bit[x]+=1;
        x+=(x&-x);
    }
}
ll sum(ll x)
{
    ll res=0;
    //cout<<x<<"\t";
    while(x>0)
    {
        //cout<<x<<" "<<bit[x]<<"  ";
        res+=bit[x];
        x-=(x&-x);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,x,y;
    ll prevx=0,prevy=0;
    vector<pair<pair<ll,ll>,ll> >vec;
    cin>>n;
    fr(i,0,n)
    {
        cin>>x>>y;
        vec.pb(mp(mp(x,y),i));
    }
    sort(vec.begin(),vec.end());
    fr(i,0,n)
    {
        //cout<<endl<<endl;
        if(prevx!=vec[i].ff.ff || prevy!=vec[i].ff.ss)
            ans[vec[i].ss]=sum(vec[i].ff.ss);
        else
            ans[vec[i].ss]=sum(vec[i].ff.ss)-1;
        add(vec[i].ff.ss);
        prevx=vec[i].ff.ff;
        prevy=vec[i].ff.ss;
    }
    fr(i,0,n)
        cout<<ans[i]<<"\n";
        //cout<<vec[i].ff.ff<<"\t"<<vec[i].ff.ss<<"\t"<<vec[i].ss<<"\n";
    return 0;
}
