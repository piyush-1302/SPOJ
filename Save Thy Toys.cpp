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
    ll t,n,val[N],dp[N];
    cin>>t;
    while(t--)
    {
        cin>>n;
        fr(i,0,n)
            cin>>val[i];
        memset(dp,0,sizeof(dp));
        frb(i,n-1,0)
        {
            dp[i]=max(dp[i],dp[i+2]+val[i]);
            if(i<=n-2)
                dp[i]=max(dp[i],dp[i+4]+val[i]+val[i+1]);
            if(i<=n-3)
                dp[i]=max(dp[i],dp[i+6]+val[i]+val[i+1]+val[i+2]);
        }
        cout<<dp[0]<<"\n";
    }
    return 0;
}
