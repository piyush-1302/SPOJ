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
        ll n,x,y,diff[N],ans=INT_MAX,sum=0;
        bool dp[207][50007];
        cin>>n;
        fr(i,0,n)
        {
            cin>>x>>y;
            diff[i]=abs(x-y);
            sum+=diff[i];
        }
        sort(diff,diff+n);
        fr(i,0,sum+1)
            dp[0][i]=false;
        fr(i,0,n+1)
            dp[i][0]=true;
        fr(i,1,n+1)
        {
            fr(j,1,sum+1)
            {
                if(diff[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j-diff[i-1]] || dp[i-1][j];
            }
        }
        fr(i,0,sum+1)
        {
           //cout<<dp[n][i]<<"\t";
            if(dp[n][i]==true)
                ans=min(ans,abs(sum-2*i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
