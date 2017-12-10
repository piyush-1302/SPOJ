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
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,a[N],sum[N],w,x,y,z;
        cin>>n>>q;
        sum[0]=0;
        a[0]=0;
        fr(i,1,n+1)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            a[i]=a[i]*i;
            a[i]=a[i-1]+a[i];
        }
        while(q--)
        {
            ll ans=0;
            cin>>w>>x>>y>>z;
            ans+=((w-x)*(sum[x+z]-sum[x+y-1]));
            ans%=mod;
            ans+=(a[x+z]-a[x+y-1]);
            ans%=mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
