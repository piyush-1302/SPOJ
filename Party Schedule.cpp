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
ll fun[N],fee[N],dp[N][N];
ll rec(ll index, ll rembudget)
{
    ll pr1=0,pr2=0;
    if(rembudget<=0)
        return 0;
    if(index<0)
        return 0;
    if(dp[index][rembudget]!=-1)
        return dp[index][rembudget];
    if(rembudget>=fee[index])
        pr1=fun[index]+rec(index-1,rembudget-fee[index]);
    pr2=rec(index-1,rembudget);
    //cout<<pr1<<"\t"<<pr2<<"\n";
    dp[index][rembudget]=max(pr1,pr2);
    return dp[index][rembudget];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll parties,budget,i,ans,ans1,flag=1;
    while(flag)
    {
        cin>>budget>>parties;
        if(parties==0 && budget==0)
        {
            flag=0;
            break;
        }
        fr(i,0,parties)
        {
            cin>>fee[i]>>fun[i];
        }
        fr(i,0,102)
        {
        	fr(j,0,502)
        		dp[i][j]=-1;
        }
        fr(i,0,502)
            rec(parties-1,i);
        ans=rec(parties-1,budget);
        fr(i,0,502)
        {
            if(dp[parties-1][i]==ans)
            {
                ans1=i;
                break;
            }
        }
        cout<<ans1<<" "<<ans<<"\n";
    }
    return 0;
}
