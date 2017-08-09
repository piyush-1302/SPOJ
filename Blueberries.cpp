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
#include<limit>*/
using namespace std;
#define ll int
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
const int N=1007;
ll dp[N][N],a[N],n;
ll rec(ll start, ll last, ll limit)
{
    if(start>n)
    {
        cout<<"H   "<<last<<"\n";
        return last;
    }
    if(dp[start][last]!=-1)
    {
        cout<<"IJH   "<<dp[start][last]<<"\n";
        return dp[start][last];
    }
    if(a[start]+last<=limit)
        dp[start][last]=max(rec(start+2,a[start]+last,limit),rec(start+1,last,limit));
    else
        dp[start][last]=rec(start+1,last,limit);
    cout<<dp[start][last]<<"\n";
    return dp[start][last];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,limit,i,j,ans;
    cin>>t;
    frn(i,1,t)
    {
        cin>>n>>limit;
        fr(j,0,n)
        cin>>a[j];
        memset(dp,-1,sizeof dp);
        ans=rec(0,0,limit);
        cout<<"Scenario #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
