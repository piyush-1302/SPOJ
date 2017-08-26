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
int main()
{
    ios_base::sync_with_stdio(false);
    ll dp[32][N];
    frn(i,0,32)
    {
        frn(j,0,1001)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(j<i*i)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j%(i*i)]+j/(i*i));
        }
    }
    ll t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cout<<dp[31][a]<<"\n";
    }
    return 0;
}
