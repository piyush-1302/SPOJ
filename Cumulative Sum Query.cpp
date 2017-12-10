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
    ll mid=(low+high)/2;
    buildtree(a,segtree,low,mid,2*pos);
    buildtree(a,segtree,mid+1,high,2*pos+1);
    segtree[pos]=segtree[2*pos+1]+segtree[pos*2];
}
ll querry(ll segtree[], ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if(qlow<=low && qhigh>=high)
        return segtree[pos];
    if(qlow>high || qhigh<low)
        return 0;
    ll mid;
    mid=(low+high)/2;
    return (querry(segtree,qlow,qhigh,low,mid,2*pos)+querry(segtree,qlow,qhigh,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,q;
    ll a[N],segtree[4*N],i,l,r;
    cin>>n;
    fr(i,1,n+1)
    {
        cin>>a[i];
    }
    cin>>q;
    buildtree(a,segtree,1,n,1);
    while(q--)
    {
        cin>>l>>r;
        cout<<querry(segtree,l+1,r+1,1,n,1)<<"\n";
    }
    return 0;
}
