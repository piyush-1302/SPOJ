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
const int N=507;
ll dp[N][N],col[N];
ll csum(ll a, ll b)
{
    ll sum=0;
    frn(i,a,b)
    {
        sum+=col[i];
        sum%=100;
    }
    return sum;
}
ll rec(ll a, ll b)
{
    if(a==b)
        return 0;
    if(dp[a][b]!=-1)
        return dp[a][b];
    ll temp=dp[a][b],check;
    frn(i,a,b-1)
    {
        check=rec(a,i)+rec(i+1,b)+csum(a,i)*csum(i+1,b);
        if(temp==-1|| check<temp)
            temp=check;
        dp[a][b]=temp;
    }
    return dp[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i;
    while(cin>>n)
    {
        frn(i,1,n)
            cin>>col[i];
        memset(dp,-1,sizeof dp);
        rec(1,n);
        cout<<dp[1][n]<<"\n";
    }
    return 0;
}
