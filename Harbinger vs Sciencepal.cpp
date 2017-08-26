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
ll dp[250][250],diff[250];
ll rec(ll start, ll n)
{
    if(start>=n)
        retrun 0;
    if(dp[start][current])
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,ans,t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        fr(i,0,n)
        {
            cin>>a>>b;
            diff[i]=abs(a-b);
        }
        ans=rec(0,n);
        cout<<ans<<"\n";
    }
    return 0;
}

