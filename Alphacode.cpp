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
const int N=5007;
int main()
{
    ll ans,i,j,dp[N],flag=0;
    char s[5007];
    cin>>s;
    while(s[0]!='0')
    {
        ll n=strlen(s);
        fr(i,0,N)
        dp[i]=0;
        dp[0]=1;
        fr(i,1,n)
        {
            if(s[i]!='0')
                dp[i]=dp[i-1];
            if(((s[i-1]-'0')*10+(s[i]-'0')<=26) && ((s[i-1]-'0')*10+(s[i]-'0'))>=10)
            {
                if(i==1)
                    dp[i]=dp[i]+1;
                else
                    dp[i]=dp[i]+dp[i-2];
            }
            //cout<<dp[i]<<"\n";
        }
        cout<<dp[n-1]<<"\n";
        cin>>s;
    }
    return 0;
}
