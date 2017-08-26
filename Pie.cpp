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
#define pi 3.1415
const int N=10007;
ll n,f,radius[N];
long double volume[N];
ll check(long double vol)
{
    ll fr=0;
    if(vol==0)
        return 0;
    fr(i,0,n)
    fr+=(ll)(volume[i]/vol);
    if(f<=fr)
        return 1;
    else
        return 0;
}
long double bs()
{
    ll mid,low,high;
    low=0;
    high=volume[n-1];
    while(high-low>=1e-6)
    {
        mid=(low+high)/2;
        if(check(mid)==1)
            low=mid;
        else
            high=mid;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,radius[N],t;
    long double ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>f;
        fr(i,0,n)
        cin>>radius[i];
        sort(radius,radius+n);
        fr(i,0,n)
        volume[i]=radius[i]*radius[i]*pi;
        ans=bs();
        cout<<setprecision(5);
        cout<<ans<<"\n";
    }
    return 0;
}
