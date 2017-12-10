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
    ll j,a[27],dp[27],n,i;
    cin>>n;
    fr(i,0,n)
    {
        cin>>a[i];
        dp[i]=1;
    }
    i=1;
    j=0;
    ll ans=1;
    while(i<n)
    {
        while(j<i)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
            j++;
        }
        i++;
        j=0;
    }
    cout<<ans<<"\n";
    return 0;
}
