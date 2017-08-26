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
#include<tuple>
#include<set>
#include<limit>*/
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
const int N=1000007;
ll a[N],k;
bool check(ll m, ll n)
{
    ll cnt=0;
    fr(i,0,n)
    {
        if(a[i]-m>0)
            cnt+=(a[i]-m);
    }
    if(cnt>=k)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,ans=0,mid,l,r,n;
    cin>>n>>k;
    fr(i,0,n)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    l=0;
    r=a[n-1];
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid,n))
        {
            ans=max(mid,ans);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}
