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
#include<set>
#include<limit>*/
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
const int N=1007;
ll a[N];
ll dp[N][N];
ll rec(ll start, ll last)
{
    //cout<<dp[start][last]<<"\n";
    //cout<<start<<"\t"<<last<<"\n";
    ll sum1,sum2;
    if(start>last)
        return 0;
    if(dp[start][last]!=-1)
        return dp[start][last];
    //taking the left element for player 1.
    if(a[start+1]>=a[last])
        sum1=a[start]+rec(start+2,last);
    else if(a[start+1]<a[last])
        sum1=a[start]+rec(start+1,last-1);

   // cout<<sum1<<"\n";
    if(a[start]>=a[last-1])
        sum2=a[last]+rec(start+1,last-1);
    else if(a[start]<a[last-1])
        sum2=a[last]+rec(start,last-2);

   // cout<<sum2<<"\n\n";
    dp[start][last]=max(sum1,sum2);
    return dp[start][last];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,ans,sum,cnt=0,ans1;
    cin>>n;
    while(n)
    {
        sum=0;
        cnt++;
        fr(i,0,n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        //cout<<sum<<"\n";
        frn(j,0,n)
        {
            frn(i,0,n)
                dp[i][j]=-1;
        }
        /*
        fr(i,0,n)
            dp[i][i]=a[i];*/
        ans1=rec(0,n-1);
       /* fr(i,0,n)
        {
            fr(j,0,n)
                cout<<dp[i][j]<<"\t";
            cout<<"\n";
        }
        //cout<<ans<<"\n";*/
        ans=sum-ans1;
        cout<<"In game "<<cnt<<", the greedy strategy might lose by as many as "<<ans1-ans<<" points.\n";
        cin>>n;
    }
    return 0;
}
