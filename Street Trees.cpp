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
ll gcd(ll a, ll b)
{
    if(b>a)
        return gcd(b,a);
    else if(b!=0)
        return gcd(b,a%b);
    else
        return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,a[N],diff,ans=0,h;
    cin>>n;
    fr(i,0,n)
        cin>>a[i];
    h=a[1]-a[0];
    fr(i,1,n)
    {
        diff=a[i]-a[i-1];
        h=gcd(h,diff);
    }
    fr(i,1,n)
    {
        diff=a[i]-a[i-1];
        ans+=((diff/h)-1);
    }
    cout<<ans<<"\n";
    return 0;
}
