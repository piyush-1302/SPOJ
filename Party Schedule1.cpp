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
int main()
{
    ios_base::sync_with_stdio(false);
    ll budget,parties,i,j,flag=1,fee[107],fun[107],dp[N][N],ans;
    while(flag)
    {
        cin>>budget>>parties;
        if(budget==0 && parties==0)
        {
            flag=0;
            break;
        }
        frn(i,1,parties)
        cin>>fee[i]>>fun[i];
        frn(i,0,parties)
            dp[i][0]=0;
        frn(j,0,budget)
            dp[0][j]=0;
        frn(i,0,parties)
        {
            frn(j,0,budget)
            {
                if(i!=0 && j!=0)
                {
                    if(j>=fee[i])
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-fee[i]]+fun[i]);
                    }
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
       //cout<<dp[parties][budget]<<"\n\n";
        frn(i,1,budget)
        {
            if(dp[parties][i]==dp[parties][budget])
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<" "<<dp[parties][budget]<<"\n";
    }
    return 0;
}
