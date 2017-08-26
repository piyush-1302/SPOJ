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
const int N=100007;
map<ll,ll>dp;
ll rec(ll n)
{
    if(n==0)
        return 0;
    if(dp.find(n)!=dp.end())
        return dp[n];
    dp[n]=max(n,rec(n/2)+rec(n/3)+rec(n/4));
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,ans=0;
    //cin>>n;
    dp.clear();
    while(cin>>n)
    {
        ans=rec(n);
        cout<<ans<<"\n";
        //cin>>n;
    }
    return 0;
}
