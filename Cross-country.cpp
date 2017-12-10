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
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,ans=0,dp[2007][2007];
        vector<ll>agnes;
        vector<ll>tom;
        while(1)
        {
            cin>>x;
            if(x==0)
                break;
            agnes.pb(x);
        }
        /*fr(i,0,agnes.size())
	cout<<agnes[i]<<"   ";
        cout<<endl;*/
        while(1)
        {
            cin>>x;
            if(x==0)
                break;
            tom.pb(x);
            while(1)
            {
                cin>>x;
                if(x==0)
                    break;
                tom.pb(x);
            }
           /* fr(i,0,tom.size())
                cout<<tom[i]<<"   ";
            cout<<endl;*/
            memset(dp,0,sizeof(dp));
            fr(i,1,agnes.size()+1)
            {
                fr(j,1,tom.size()+1)
                {
                    if(agnes[i-1]==tom[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            ans=max(ans,dp[agnes.size()][tom.size()]);
            tom.clear();
        }
        cout<<ans<<"\n";
        agnes.clear();
    }
    return 0;
}
