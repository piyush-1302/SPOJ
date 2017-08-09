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
bool dp[105][N];
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,sum,ans,j,ar[107];
    cin>>t;
    while(t--)
    {
        sum=0;
        ans=0;
        cin>>n;
        fr(i,1,n+1)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        sort(ar+1,ar+n+1);
        frn(i,0,n)
        {
            frn(j,0,sum)
            {
                if(j==0)
                    dp[i][j]=true;
                else
                    dp[i][j]=false;
            }
        }
        frn(i,1,n)
        {
            frn(j,1,sum)
            {
                if(ar[i]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-ar[i]];
                //cout<<dp[i][j]<<"\t";
            }
            //cout<<"\n";
        }
        frn(i,1,sum)
        {
           // cout<<dp[n][i]<<"\t";
            if(dp[n][i]==true)
            {
                //cout<<i<<"\t";
                ans+=i;
                //cout<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
