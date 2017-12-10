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
void buildtree(ll segtree[],ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=0;
        return;
    }
    ll mid=(low+high)>>1;
    buildtree(segtree,low,mid,2*pos);
    buildtree(segtree,mid+1,high,2*pos+1);
    segtree[pos]=segtree[pos*2]+segtree[2*pos+1];
}
void update(ll segtree[], ll lazy[], ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(lazy[pos]!=0)
    {
        segtree[pos]=(high-low+1)-segtree[pos];
        if(low!=high)
        {
            lazy[2*pos]=!lazy[2*pos];
            lazy[2*pos+1]=!lazy[2*pos+1];
        }
        lazy[pos]=0;
    }
    if(low>high || low>hdx || high<ldx)
        return;
    if(low>=ldx && high<=hdx)
    {
        segtree[pos]=(high-low+1)-segtree[pos];
        if(low!=high)
        {
            lazy[2*pos]=!lazy[2*pos];
            lazy[2*pos+1]=!lazy[2*pos+1];
        }
        return;
    }
    ll mid=(low+high)>>1;
    update(segtree,lazy,ldx,hdx,low,mid,2*pos);
    update(segtree,lazy,ldx,hdx,mid+1,high,2*pos+1);
    segtree[pos]=segtree[2*pos]+segtree[2*pos+1];
}
ll querry(ll segtree[],ll lazy[], ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(lazy[pos]!=0)
    {
        segtree[pos]=(high-low+1)-segtree[pos];
        if(low!=high)
        {
            lazy[2*pos]=!lazy[pos];
            lazy[2*pos+1]=!lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>high || low>hdx || high<ldx)
        return 0;
    if(low>=ldx && high<=hdx)
    {
        return segtree[pos];
    }
    ll mid=(low+high)>>1;
    return (querry(segtree,lazy,ldx,hdx,low,mid,2*pos)+querry(segtree,lazy,ldx,hdx,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,c,x,p,q,v;
    cin>>n>>c;
    ll segtree[4*N],lazy[4*N];
    buildtree(segtree,1,n,1);
    memset(lazy,0,sizeof(lazy));
    while(c--)
    {
        cin>>x;
        if(x==0)
        {
            cin>>p>>q;
            update(segtree,lazy,p,q,1,n,1);
        }
        else
        {
            cin>>p>>q;
            cout<<querry(segtree,lazy,p,q,1,n,1)<<"\n";
        }
    }
    return 0;
}

