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
ll a[N];
bool bs(ll ind, ll n, ll k)
{
    ll low,high,mid;
    low=ind;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]-a[ind]==k)
            return true;
        else if(a[mid]-a[ind]>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,x,ans;
    cin>>n>>k;
    fr(i,0,n)
    {
        cin>>a[i];
        //vec.pb(x);
    }
    sort(a,a+n);
    ans=0;
    fr(i,0,n)
    {
        if(bs(i,n,k))
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
