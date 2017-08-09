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
const int N=100007;
ll a[N];
ll c;
ll check(ll n,ll mid)
{
    ll pr=a[0],cnt=1;
    //cout<<mid<<"\n";
    fr(i,1,n)
    {
      //  cout<<"HIw "<<a[i]<<"\t"<<pr<<"\n";
        if(a[i]-pr>=mid)
        {
            pr=a[i];
            cnt++;
        }
        if(cnt>=c)
            return 1;
        //cout<<"HI "<<cnt<<"\t";
    }
    //cout<<"\n";
    return 0;
}
ll bs(ll n)
{
    ll l,r,mid,ans=0;
    l=0;
    r=a[n-1];
    while(l<=r)
    {
        mid=(l+r)/2;
      //  cout<<"\n"<<mid<<"\n";
        if(check(n,mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,i,ans,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        fr(i,0,n)
        cin>>a[i];
        sort(a,a+n);
        ans=bs(n);
        cout<<ans<<"\n";
    }
    return 0;
}
