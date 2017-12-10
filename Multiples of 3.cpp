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
ll a,b,c;
ll segtree[4*N][3]={0},lazy[4*N]={0};
void buildtree(ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos][0]=1;
        return;
    }
    ll mid=(low+high)>>1;
    buildtree(low,mid,2*pos);
    buildtree(mid+1,high,2*pos+1);
    segtree[pos][0]=segtree[2*pos][0]+segtree[2*pos+1][0];
}
void update(ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(lazy[pos])
    {
        if(low!=high)
        {
            lazy[2*pos]=(lazy[pos]+lazy[2*pos])%3;
            lazy[2*pos+1]=(lazy[pos]+lazy[2*pos+1])%3;
        }
        a=segtree[pos][0];
        b=segtree[pos][1];
        c=segtree[pos][2];
        segtree[pos][1]=a;
        segtree[pos][2]=b;
        segtree[pos][0]=c;
        if(lazy[pos]==2)
        {
            a=segtree[pos][0];
            b=segtree[pos][1];
            c=segtree[pos][2];
            segtree[pos][1]=a;
            segtree[pos][2]=b;
            segtree[pos][0]=c;
        }
        lazy[pos]=0;
    }
    if(low>high || ldx>high || hdx<low)
        return;
    if(ldx<=low && hdx>=high)
    {
        a=segtree[pos][0];
        b=segtree[pos][1];
        c=segtree[pos][2];
        segtree[pos][1]=a;
        segtree[pos][2]=b;
        segtree[pos][0]=c;
        if(low!=high)
        {
            lazy[2*pos]=(1+lazy[2*pos])%3;
            lazy[2*pos+1]=(1+lazy[2*pos+1])%3;
        }
        return;
    }
    ll mid=(low+high)>>1;
    update(ldx,hdx,low,mid,2*pos);
    update(ldx,hdx,mid+1,high,2*pos+1);
    segtree[pos][0]=segtree[2*pos][0]+segtree[2*pos+1][0];
    segtree[pos][1]=segtree[2*pos][1]+segtree[2*pos+1][1];
    segtree[pos][2]=segtree[2*pos][2]+segtree[2*pos+1][2];
}
ll querry(ll ldx,ll hdx,ll low,ll high, ll pos)
{
    if(lazy[pos])
    {
        if(low!=high)
        {
            lazy[2*pos]=(lazy[pos]+lazy[2*pos])%3;
            lazy[2*pos+1]=(lazy[pos]+lazy[2*pos+1])%3;
        }
        a=segtree[pos][0];
        b=segtree[pos][1];
        c=segtree[pos][2];
        segtree[pos][1]=a;
        segtree[pos][2]=b;
        segtree[pos][0]=c;
        if(lazy[pos]==2)
        {
            a=segtree[pos][0];
            b=segtree[pos][1];
            c=segtree[pos][2];
            segtree[pos][1]=a;
            segtree[pos][2]=b;
            segtree[pos][0]=c;
        }
        lazy[pos]=0;
    }
    if(low>high || ldx>high || hdx<low)
        return 0;
    if(ldx<=low && hdx>=high)
        return segtree[pos][0];
    ll mid=(low+high)>>1;
    return (querry(ldx,hdx,low,mid,2*pos)+querry(ldx,hdx,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    buildtree(1,n,1);
    ll x,y,z;
    while(k--)
    {
        cin>>z>>x>>y;
        if(z==0)
            update(x+1,y+1,1,n,1);
        else
            cout<<querry(x+1,y+1,1,n,1)<<"\n";
    }
    return 0;
}
