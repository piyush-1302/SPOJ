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
    if(high==low)
    {
        segtree[pos]=a[low];
        return;
    }
    ll mid;
    mid=(high+low)/2;
    buildtree(a,segtree,low,mid,2*pos);
    buildtree(a,segtree,mid+1,high,2*pos+1);
    segtree[pos]=min(segtree[2*pos],segtree[2*pos+1]);
}
ll querry(ll segtree[], ll l, ll r, ll low, ll high, ll pos)
{
    if(l<=low && r>=high)
        return segtree[pos];
    if(low>r || high<l)
        return INT_MAX;
    ll mid;
    mid=(low+high)/2;
    return min(querry(segtree,l,r,low,mid,2*pos),querry(segtree,l,r,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,a[N],segtree[4*N],i,ans,x,y,q;
    cin>>n;
    fr(i,1,n+1)
        cin>>a[i];
    buildtree(a,segtree,1,n,1);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        ans=querry(segtree,x+1,y+1,1,n,1);
        cout<<ans<<"\n";
    }
    return 0;
}
