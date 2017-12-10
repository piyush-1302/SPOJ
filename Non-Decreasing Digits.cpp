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
        ll n,i,j,x,dp[1007][67];
        cin>>x>>n;
        fr(i,0,10)
        {
            dp[1][i]=i+1;
            dp[0][i]=0;
        }
        fr(i,1,n+1)
            dp[i][0]=1;
        fr(i,2,n+1)
        {
            fr(j,1,10)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        cout<<x<<" "<<dp[n][9]<<"\n";
    }
    return 0;
}
