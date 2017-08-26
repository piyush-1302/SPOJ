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
ll n,k,a[N];
ll solve(ll x)
{
    ll j;
    j=k;
    frb(i,n-1,0)
    {
        j-=(a[i]/x);
        if(j<=0)
            return 1;
    }
    return 0;
}
ll bs()
{
    ll low,high,mid;
    low=1;
    high=a[n-1];
    while(low<=high)
    {
        mid=(low+high)/2;
        if(solve(mid))
            low=mid+1;
        else
            high=mid-1;
    }
    return low-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll ans,i,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        fr(i,0,n)
        cin>>a[i];
        sort(a,a+n);
        ans=bs();
        cout<<ans<<"\n";
    }
    return 0;
}
