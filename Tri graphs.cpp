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
#include<iterator>*/
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
const int N=100007;
int main()
{
    ll n,i,j,a[N][4],dp[N][4],x,cnt=0,flag=1;
    while(flag)
    {
        cnt++;
        cin>>n;
        frn(i,1,n)
        {
            frn(j,1,3)
            {
                cin>>a[i][j];
            }
        }
        if(n==0)
        {
            flag=0;
            break;
        }
        dp[0][0]=0;
        frn(i,1,n)
        {
            if(i==1)
            {
                dp[i][2]=a[i][2];
                dp[i][3]=a[i][3]+dp[i][2];
            }
            else if(i==2)
            {
                dp[i][1]=dp[i-1][2]+a[i][1];
                dp[i][2]=min(dp[i][1]+a[i][2],min(dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2]));
                dp[i][3]=min(dp[i-1][2]+a[i][3],min(dp[i-1][3]+a[i][3],dp[i][2]+a[i][3]));
            }
            else
            {
                dp[i][1]=min(dp[i-1][1]+a[i][1],dp[i-1][2]+a[i][1]);
                dp[i][2]=min(dp[i][1]+a[i][2],min(dp[i-1][1]+a[i][2],min(dp[i-1][2]+a[i][2],dp[i-1][3]+a[i][2])));
                dp[i][3]=min(dp[i-1][2]+a[i][3],min(dp[i-1][3]+a[i][3],dp[i][2]+a[i][3]));
            }
           // cout<<dp[i][1]<<"\t"<<dp[i][2]<<"\t"<<dp[i][3]<<"\n";
        }
        cout<<cnt<<". "<<dp[n][2]<<"\n";
    }
    return 0;
}

