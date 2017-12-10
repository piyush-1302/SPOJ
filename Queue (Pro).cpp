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
const int N=10007;
ll segtree[4*N];
void buildtree(ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=1;
        return ;
    }
    ll mid=(low+high)>>1;
    buildtree(low,mid,2*pos);
    buildtree(mid+1,high,2*pos+1);
    segtree[pos]=segtree[pos*2]+segtree[2*pos+1];
}
ll querry(ll reqd, ll low, ll high, ll pos)
{
    if(low==high)
        return low;
    ll mid=(low+high)>>1;
    if(segtree[2*pos]>=reqd)
        return querry(reqd,low,mid,2*pos);
    else
        return querry(reqd-segtree[2*pos],mid+1,high,2*pos+1);
}
void update(ll pos1, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=0;
        return ;
    }
    ll mid=(low+high)>>1;
    if(mid>=pos1)
        update(pos1,low,mid,2*pos);
    else
        update(pos1,mid+1,high,2*pos+1);
    segtree[pos]=segtree[2*pos]+segtree[2*pos+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        vector<pii>vec;
        ll ar[N],n,x,a[N];
        cin>>n;
        fr(i,0,n)
            cin>>a[i];
        fr(i,0,n)
        {
            cin>>x;
            vec.pb(mp(a[i],x));
        }
        sort(vec.begin(),vec.end());
        buildtree(1,n,1);
        fr(i,0,vec.size())
        {
            ll pos=querry(vec[i].ss+1,1,n,1);
            ar[pos]=vec[i].ff;
            update(pos,1,n,1);
        }
        fr(i,1,n+1)
            cout<<ar[i]<<" ";
        cout<<"\n";
        vec.clear();
    }
    return 0;
}
