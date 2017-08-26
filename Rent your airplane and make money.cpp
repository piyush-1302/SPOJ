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
#include<iterator>*/
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
const int N=20007;
struct com
{
    ll st;
    ll d;
    ll cost;
};
com a[N];
/*bool compare(const tup &lhs, const tup &rhs)
{
    return get<0>(lhs)< get<0>(rhs);
}*/
bool operator< (const com& x, const com& y)
{
	if(x.st!=y.st)
		return x.st<y.st;
	else
		return x.d<y.d;

}
ll ans[N];

ll bs(ll l, ll r, ll x)
{
    ll mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid].st>x)
            r=mid-1;
        else
            l=mid+1;
    }
    if(a[l].st>x)
        return l;
    else
        return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,s,d,cost,i,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        fr(i,0,n)
        {
            cin>>a[i].st>>a[i].d>>a[i].cost;
            a[i].d+=a[i].st;
        }
        sort(a,a+n);
        ans[n-1]=a[n-1].cost;
        frb(i,n-2,0)
        {
            if(a[i].d<a[n-1].st)
            {
                b=bs(i,n-1,a[i].d);
                ans[i]=max(ans[i+1],ans[b]+a[i].cost);
            }
            else
                ans[i]=max(ans[i+1],a[i].cost);
        }
        cout<<ans[0]<<"\n";
    }
    return 0;
}
