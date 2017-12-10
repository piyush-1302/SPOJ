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
void buildtree(ll a[], ll segtree[], ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=a[low];
        return;
    }
    ll mid=(low+high)>>1;
    buildtree(a,segtree,low,mid,2*pos);
    buildtree(a,segtree,mid+1,high,2*pos+1);
    segtree[pos]=segtree[2*pos]&segtree[2*pos+1];
}
ll querry(ll segtree[], ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(low==ldx && high==hdx)
        return segtree[pos];
	ll mid = (low+high)>>1;
    ll lt = pos << 1;
    ll rt = lt | 1;
	if(hdx<= mid)
        return querry(lt,low, mid, ldx, hdx);
	else if(ldx>mid)
        return querry(rt, mid + 1,high, ldx, hdx);
	else return querry(lt, low, mid, ldx, mid) & querry(rt, mid + 1, high, mid + 1, hdx);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,a[N];
    ll t;
    cin>>t;
    while(t--){
    cin>>n>>k;
    fr(i,1,n+1)
        cin>>a[i];
    ll segtree[4*N];
    buildtree(a,segtree,1,n,1);
    k=min(k,n-1);
    ll s,e,ans;
    fr(i,1,n+1)
    {
        ans=1;
        s=(i-k+n)%(n+1);
        e=(i+k)%(n+1);
        if(s>i)
            ans&=querry(segtree,s,n,1,n,1)&querry(segtree,1,i,1,n,1);
        else
            ans&=querry(segtree,s,i,1,n,1);
        if(e>i)
            ans&=querry(segtree,i,e,1,n,1);
        else
            ans&=querry(segtree,i,n,1,n,1)&querry(segtree,0,e,1,n,1);
        if(i==n)
            cout<<ans<<"\n";
        else
            cout<<ans<<" ";
    }
    }
    return 0;
}
