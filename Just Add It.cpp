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
#define mod 10000007
#define pii pair<ll,ll>
const int N=100007;
ll modinverse(ll a, ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return (ans%mod);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k;
    ll s1,s2,s3,s4;
    while(true)
    {
        cin>>n>>k;
        if(n==0 && k==0)
            break;
        s1=modinverse(n,k);
        s2=modinverse(n,n);
        s3=modinverse(n-1,k);
        s3*=2;
        s3%=mod;
        s4=modinverse(n-1,n-1);
        s4*=2;
        s4%=mod;
        cout<<(s1+s2+s3+s4)%mod<<"\n";
    }
    return 0;
}
