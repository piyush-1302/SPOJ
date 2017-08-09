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
    ll t,n,dp[N],ar[N],i;
    cin>>t;
    fr(i,1,t+1)
    {
        cin>>n;
        fr(j,0,n)
        {
            cin>>ar[j];
            dp[j]=0;
        }
        dp[0]=ar[0];
        dp[1]=max(dp[0],ar[1]);
        fr(j,2,n)
            dp[j]=max(dp[j-1],dp[j-2]+ar[j]);
        cout<<"Case "<<i<<": "<<dp[n-1]<<"\n";
    }
    return 0;
}
