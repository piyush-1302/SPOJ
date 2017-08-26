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
const int N=10007;
ll ans[N],wt[N],price[N];
ll unboundedknapsack(ll val, ll n)
{
    frn(i,1,val)
    {
       // cout<<ans[i]<<"\t";
        fr(j,0,n)
        {
            if(wt[j]<=i)
                ans[i]=min(ans[i],ans[i-wt[j]]+price[j]);
        }
      //  cout<<ans[i]<<"\n";
    }
    return ans[val];
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j,n,t,emp,full,val,temp;
    cin>>t;
    while(t--)
    {
        cin>>emp>>full;
        val=full-emp;
        cin>>n;
        fr(i,0,n)
        {
            cin>>price[i]>>wt[i];
        }
        memset(ans,1000000,sizeof ans);
        ans[0]=0;
        temp=unboundedknapsack(val,n);
        if(temp>=1000000)
        {
            cout<<"This is impossible.\n";
        }
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<temp<<".\n";
    }
    return 0;
}
