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
const int N=2007;
ll ans[N][N];
ll rec (ll x, ll y)
{
    if(x<=0 || y<=0)
        return -1;
    else
    {
        if(ans[x][y]==-1)
        {
            ans[x][y]=max(rec(x-2,y-8)+2,rec(x-17,y+7)+2);
        }
        return ans[x][y];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll h,a,t,val;
    cin>>t;
    while(t--)
    {
        cin>>h>>a;
        memset(ans,-1,sizeof ans);
        cout<<rec(h,a)<<"\n";
    }
    return 0;
}
