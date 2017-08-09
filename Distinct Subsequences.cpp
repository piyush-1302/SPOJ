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
const int N=1000007;
//bool ans[N];
int main()
{
    ll i,dp[N],last[500],t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(dp,0,sizeof dp);
        memset(last,0,sizeof last);
        dp[0]=1;
        frn(i,1,s.length())
        {
            dp[i]=(dp[i-1]*2+mod)%mod;
            if(last[s[i-1]]!=0)
                dp[i]=(dp[i]-dp[last[s[i-1]]-1]+mod)%mod;
            last[s[i-1]]=i;
        }
        cout<<dp[s.length()]<<"\n";
    }
    return 0;
}
