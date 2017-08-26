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
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,a[N],b[N],i,dp1[N],dp2[N],l;
    cin>>n>>k;
    fr(i,0,n)
        cin>>a[i];
    fr(i,0,n)
        cin>>b[i];
    dp1[0]=a[0];
    dp2[0]=b[0];
    dp1[1]=dp1[0]+a[1];
    dp2[1]=dp2[0]+b[1];
    fr(i,2,n)
    {
        dp1[i]=min(dp1[i-1]+a[i],dp2[i-1]+a[i]+b[i]);
        dp2[i]=min(dp2[i-1]+b[i],dp1[i-1]+b[i]+a[i]);
        if(dp1[i]>k && dp2[i]>k)
        {
        	l=i;
           	break;
        }
    }
    fr(i,0,n)
        cout<<dp1[i]<<"\t"<<dp2[i]<<"\n";
    cout<<l<<" "<<min(dp1[l-1],dp2[l-1])<<"\n";
    return 0;
}
