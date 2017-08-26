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
    ll n,m,k,x,y;
    cin>>n;
    while(n--)
    {
        ll dp[57][1007];
        vector<pii>vec;
        cin>>k>>m;
        fr(i,0,m)
        {
            cin>>x>>y;
            vec.pb(mp(x,y));
        }
       // sort(vec.begin(),vec.end());
        fr(i,0,k+1)
            dp[0][i]=0;
        fr(i,0,m+1)
            dp[i][0]=0;
        fr(i,1,m+1)
        {
            fr(j,1,k+1)
            {
                if(vec[i-1].ff>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vec[i-1].ff]+vec[i-1].ss);
            }
        }
        cout<<"Hey stupid robber, you can get "<<dp[m][k]<<"."<<"\n";
    }
    return 0;
}
