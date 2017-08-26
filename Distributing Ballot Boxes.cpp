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
const int N=500007;
ll a[N],b,n;
ll check(ll box)
{
    ll ans=0;
    fr(i,0,n)
    {
        if(a[i]<=box)
            ans++;
        else
        {
            if(a[i]%box!=0)
                ans++;
            ans+=(a[i]/box);
        }
    }
    return ans;
}
ll bs(ll r)
{
    ll mid,l=1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)<=b)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    ll i,ma,ans;
    cin>>n>>b;
    while(n!=-1 && b!=-1)
    {
        ma=0;
        fr(i,0,n)
        {
            cin>>a[i];
            if(a[i]>ma)
                ma=a[i];
        }
        ans=bs(ma);
        cout<<ans<<"\n";
        cin>>n>>b;
    }
    return 0;
}

