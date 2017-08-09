#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=500007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll ans,a[N],i,temp,n;
    ssi(n);
    fr(i,0,n)
    ssi(a[i]);
    temp=a[0];
    fr(i,1,n)
    {
        ans=a[i]^temp;
        temp=ans;
    }
    cout<<ans<<"\n";
    return 0;
}
