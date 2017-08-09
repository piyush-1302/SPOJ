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
const int N=100007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,dp[2002][2002],j,t,l1,l2;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        fr(i,0,2002)
        {
            fr(j,0,2002)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else
                    dp[i][j]=0;
            }
        }
        l1=s1.length();
        l2=s2.length();
        fr(i,0,l2)
        {
            fr(j,0,l1)
            {
            //	cout<<dp[i][j]<<"\t";
                if(s1[j]==s2[i])
                    dp[i+1][j+1]=dp[i][j];
                else
                    dp[i+1][j+1]=min(dp[i][j],min(dp[i][j+1],dp[i+1][j]))+1;

            }
            //cout<<"\n";
        }
        cout<<dp[l2][l1]<<"\n";
    }
    return 0;
}
