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
void buildtree(ll a[], ll seg[], ll l, ll r, ll pos)
{
    ll mid;
    if(l==r)
    {
    	seg[pos]=a[l];
    	return ;
    }
    mid=(l+r)/2;
    buildtree(a,seg,l,mid,2*pos+1);
    buildtree(a,seg,mid+1,r,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[pos*2+2]);
}
ll querry(ll seg[], ll x, ll y, ll l, ll r, ll pos)
{
    if(x>r || y<l)
        return INT_MAX;
    if(x<=l && y>=r)
        return seg[pos];
    ll mid;
    mid=(l+r)/2;
    return min(querry(seg,x,y,l,mid,2*pos+1),querry(seg,x,y,mid+1,r,2*pos+2));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        ll n,q,i,a[N],seg[4*N],x,y;
        cin>>n>>q;
        fr(i,0,n)
            cin>>a[i];
        buildtree(a,seg,0,n-1,0);
        cout<<"Scenario #"<<j<<":\n";
        for(i=1;i<=q;i++)
        {
            cin>>x>>y;
            cout<<querry(seg,x-1,y-1,0,n-1,0)<<"\n";
        }
    }
    return 0;
}
